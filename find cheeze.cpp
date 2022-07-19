#include <stdio.h>
#pragma warning (disable:4996)

#define SZ 8 // 지도크기가 가로 8, 세로 8이므로

struct coord
{
    int row;
    int col;
};

struct vertex_info
{
    int prev_row; // 바로 직전에 방문한 vertex의 row
    int prev_col; // 바로 직전에 방문한 vertex의 column
    int found; // 최종 경로를 찾았는지? 1, 아니면 0
    int dist; // 거리
};

struct vertex_info vertexes[SZ][SZ];

char map[SZ][SZ] =
{
   {'.', 'x', '.', 'x', '.', '.', '.', 'x'},
   {'.', 'x', '.', 'x', '.', 'x', '.', 'x'},
   {'.', 'x', '.', 'x', '.', 'x', '.', '.'},
   {'.', 'x', '.', '.', '.', 'x', 'x', '.'},
   {'.', 'x', '.', 'x', 'x', 'x', 'x', '.'},
   {'.', 'x', '.', 'x', '.', 'x', '.', '.'},
   {'.', 'x', '.', '.', '.', 'x', '.', 'x'},
   {'.', '.', '.', 'x', '.', 'x', '.', '.'}
};

/*
   Dijkstra 알고리즘 수행에 필요한 테이블 초기화
*/

void initVertexInfo(void)
{
    int i, j;

    for (i = 0; i < SZ; i++)
    {
        for (j = 0; j < SZ; j++)
        {
            vertexes[i][j].dist = 999999; // 무한대
            vertexes[i][j].prev_row = -1; // 직전에 누구를 거쳤는지 모르기 때문에 -1
            vertexes[i][j].prev_col = -1; // 직전에 누구를 거쳤는지 모르기 때문에 -1
            vertexes[i][j].found = 0;
        }
    }
}

// 1. (me_row, me_col) --> (row, col)로 이동이 가능한지?
// 2. (me_row, me_col) ---> (row, col)로 빨리 갈 수 있는 길이 있는지?

void checkNeighbor(int row, int col, int me_row, int me_col)
{
    if (row >= 0 && col >= 0 && row < SZ && col < SZ &&
        map[row][col] == '.' && // 갈 수 있는 곳. 길이 있음 '.'
        vertexes[row][col].found == 0) // 최단 경로가 아직 알려지지 않은 곳
    {
        // 업데이트 할 수 있는 마지막 조건은,
        // me_row, me_col을 통해서 row, col까지 지금까지 알려진 것보다 더
        // 빨리 갈 수 있을 경우에만 Update...

        // vertexes[me_row][me_col].dist + 1: (me_row, me_col)을 거쳐서, (row, col)갈 때의 거리
        // +1을 하는 이유:(me_row, me_col)에서 (row, col)로 이동하는 것은 1칸이기 때문에.
        // vertexes[row][col].dist : 지금까지 알려진 (row, col) 까지의 거리
        // 지금까지 알려진 것보다, (me_row, me_col)을 거치는 새 경로가 더 가깝다면
        // 업데이트
        if (vertexes[row][col].dist > vertexes[me_row][me_col].dist + 1)
        {
            // 이제, (row, col)까지 가는 경로를
            // (me_row, me_col)을 거쳐서 가는 것으로 업데이트
            vertexes[row][col].dist = vertexes[me_row][me_col].dist + 1;
            vertexes[row][col].prev_col = me_col;
            vertexes[row][col].prev_row = me_row;
        }

    }
}

// found == 0이면서
// dist가 가장 짧은 vertex의 (row, col)을
// struct coord에 담아서 반환
struct coord findNextVertex(void)
{
    int i, j;
    struct coord sm_coord;
    int smallest_dist = 999999;

    sm_coord.row = -1;
    sm_coord.col = -1;

    for (i = 0; i < SZ; i++)
    {
        for (j = 0; j < SZ; j++)
        {
            if (vertexes[i][j].found == 0 && vertexes[i][j].dist < smallest_dist)
            {
                sm_coord.row = i;
                sm_coord.col = j;
                smallest_dist = vertexes[i][j].dist;
            }
        }
    }

    return sm_coord;
}

void checkAllNeighbors(int me_row, int me_col) // 이동할 수 있는 상하좌우 위치정보 Update
{
    checkNeighbor(me_row - 1, me_col, me_row, me_col); // 나의 위치에서 왼
    checkNeighbor(me_row + 1, me_col, me_row, me_col); // 나의 위치에서 오
    checkNeighbor(me_row, me_col - 1, me_row, me_col); // 나의 위치에서 아래
    checkNeighbor(me_row, me_col + 1, me_row, me_col); // 나의 위치에서 위
}

void showMap(void)
{
    int i, j;

    for (i = 0; i < SZ; i++)
    {
        for (j = 0; j < SZ; j++)
        {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    struct coord next; // 다음 번에 방문할 vertex의 row, col
    int r, c;

    initVertexInfo();

    int start_row, start_col;
    int goal_row, goal_col;

    scanf("%d %d", &start_row, &start_col);
    scanf("%d %d", &goal_row, &goal_col);

    vertexes[start_row][start_col].dist = 0;
    vertexes[start_row][start_col].found = 1; // 시작하는 노드이기  때문에, 최단거리가 바로 결정

    checkAllNeighbors(start_row, start_col);

    // Dijkstra 알고리즘 수행완료
    while (1)
    {
        next = findNextVertex(); // 최단 경로가 알려지지 않은 vertex 중에, 경로가 제일 짧은 것

        if ((next.row == -1) && (next.col == -1))
        {
            break;
        }

        vertexes[next.row][next.col].found = 1;
        checkAllNeighbors(next.row, next.col);
    }

    // 찾은 경로를 보여주자.
    // Dijkstra 알고리즘 특성상, 최종 도착지부터 거꾸로 추적해 오면
    // 경로를 알 수 있다.

    r = goal_row;
    c = goal_col;

    while (1)
    {
        int prev_row, prev_col;

        if (r == goal_row && c == goal_col)
        {
            map[r][c] = '*';
        }
        else
        {
            map[r][c] = 'o'; // 지도 상에서 어떤 경로를 거쳤는지 보여주기 위한 표시
        }


        prev_row = vertexes[r][c].prev_row;
        prev_col = vertexes[r][c].prev_col;

        if (prev_row == start_row && prev_col == start_col) // 시작점으로 돌아왔음.
        {
            map[prev_row][prev_col] = 'o';
            break;
        }

        r = prev_row;
        c = prev_col;
    }

    showMap();

    return 0;
}
