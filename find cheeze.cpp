#include <stdio.h>
#pragma warning (disable:4996)

#define SZ 8 // ����ũ�Ⱑ ���� 8, ���� 8�̹Ƿ�

struct coord
{
    int row;
    int col;
};

struct vertex_info
{
    int prev_row; // �ٷ� ������ �湮�� vertex�� row
    int prev_col; // �ٷ� ������ �湮�� vertex�� column
    int found; // ���� ��θ� ã�Ҵ���? 1, �ƴϸ� 0
    int dist; // �Ÿ�
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
   Dijkstra �˰��� ���࿡ �ʿ��� ���̺� �ʱ�ȭ
*/

void initVertexInfo(void)
{
    int i, j;

    for (i = 0; i < SZ; i++)
    {
        for (j = 0; j < SZ; j++)
        {
            vertexes[i][j].dist = 999999; // ���Ѵ�
            vertexes[i][j].prev_row = -1; // ������ ������ ���ƴ��� �𸣱� ������ -1
            vertexes[i][j].prev_col = -1; // ������ ������ ���ƴ��� �𸣱� ������ -1
            vertexes[i][j].found = 0;
        }
    }
}

// 1. (me_row, me_col) --> (row, col)�� �̵��� ��������?
// 2. (me_row, me_col) ---> (row, col)�� ���� �� �� �ִ� ���� �ִ���?

void checkNeighbor(int row, int col, int me_row, int me_col)
{
    if (row >= 0 && col >= 0 && row < SZ && col < SZ &&
        map[row][col] == '.' && // �� �� �ִ� ��. ���� ���� '.'
        vertexes[row][col].found == 0) // �ִ� ��ΰ� ���� �˷����� ���� ��
    {
        // ������Ʈ �� �� �ִ� ������ ������,
        // me_row, me_col�� ���ؼ� row, col���� ���ݱ��� �˷��� �ͺ��� ��
        // ���� �� �� ���� ��쿡�� Update...

        // vertexes[me_row][me_col].dist + 1: (me_row, me_col)�� ���ļ�, (row, col)�� ���� �Ÿ�
        // +1�� �ϴ� ����:(me_row, me_col)���� (row, col)�� �̵��ϴ� ���� 1ĭ�̱� ������.
        // vertexes[row][col].dist : ���ݱ��� �˷��� (row, col) ������ �Ÿ�
        // ���ݱ��� �˷��� �ͺ���, (me_row, me_col)�� ��ġ�� �� ��ΰ� �� �����ٸ�
        // ������Ʈ
        if (vertexes[row][col].dist > vertexes[me_row][me_col].dist + 1)
        {
            // ����, (row, col)���� ���� ��θ�
            // (me_row, me_col)�� ���ļ� ���� ������ ������Ʈ
            vertexes[row][col].dist = vertexes[me_row][me_col].dist + 1;
            vertexes[row][col].prev_col = me_col;
            vertexes[row][col].prev_row = me_row;
        }

    }
}

// found == 0�̸鼭
// dist�� ���� ª�� vertex�� (row, col)��
// struct coord�� ��Ƽ� ��ȯ
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

void checkAllNeighbors(int me_row, int me_col) // �̵��� �� �ִ� �����¿� ��ġ���� Update
{
    checkNeighbor(me_row - 1, me_col, me_row, me_col); // ���� ��ġ���� ��
    checkNeighbor(me_row + 1, me_col, me_row, me_col); // ���� ��ġ���� ��
    checkNeighbor(me_row, me_col - 1, me_row, me_col); // ���� ��ġ���� �Ʒ�
    checkNeighbor(me_row, me_col + 1, me_row, me_col); // ���� ��ġ���� ��
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
    struct coord next; // ���� ���� �湮�� vertex�� row, col
    int r, c;

    initVertexInfo();

    int start_row, start_col;
    int goal_row, goal_col;

    scanf("%d %d", &start_row, &start_col);
    scanf("%d %d", &goal_row, &goal_col);

    vertexes[start_row][start_col].dist = 0;
    vertexes[start_row][start_col].found = 1; // �����ϴ� ����̱�  ������, �ִܰŸ��� �ٷ� ����

    checkAllNeighbors(start_row, start_col);

    // Dijkstra �˰��� ����Ϸ�
    while (1)
    {
        next = findNextVertex(); // �ִ� ��ΰ� �˷����� ���� vertex �߿�, ��ΰ� ���� ª�� ��

        if ((next.row == -1) && (next.col == -1))
        {
            break;
        }

        vertexes[next.row][next.col].found = 1;
        checkAllNeighbors(next.row, next.col);
    }

    // ã�� ��θ� ��������.
    // Dijkstra �˰��� Ư����, ���� ���������� �Ųٷ� ������ ����
    // ��θ� �� �� �ִ�.

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
            map[r][c] = 'o'; // ���� �󿡼� � ��θ� ���ƴ��� �����ֱ� ���� ǥ��
        }


        prev_row = vertexes[r][c].prev_row;
        prev_col = vertexes[r][c].prev_col;

        if (prev_row == start_row && prev_col == start_col) // ���������� ���ƿ���.
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
