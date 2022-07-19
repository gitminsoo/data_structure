// Dijkstra Algorithm
//

#include <stdio.h>

#define G_SZ 7

typedef struct {
	int prev; // 직전의 버텍스 번호
	int dist; // 목적지까지의 거리
	int done; // 최단거리를 찾으면 1 아니면 0
} DijkstraElement;


void initDTable(DijkstraElement dtable[])
{
	for (int i = 0; i < G_SZ; i++)
	{
		dtable[i].prev = -1;
		dtable[i].dist = 9999;
		dtable[i].done = 0;
	}
}

// dtable에서 dist가 가장 짧고 done 은 0인 ver찾아
// 그 번호를 반환
// 만약 모든 ver의 done 이 1이면 -1 반환 ==> Dijkstra end
int find_shortest_path_vertex(DijkstraElement dtable[])
{
	int ver_idx = -1;    // 최단 거리 결정 ver
	int ver_dist = 9999; // 그 ver의 최단거리

	for (int i = 0; i < G_SZ; i++)
	{
		if (dtable[i].done == 0 && dtable[i].dist < ver_dist)
		{
			ver_idx = i;
			ver_dist = dtable[i].dist;
		}
	}
	return ver_idx;
}

void show_dtable(DijkstraElement dtable[])
{
	for (int i = 1; i < G_SZ; i++)
	{
		printf("%5d", i);
	}
	printf("\n");

	for (int i = 1; i < G_SZ; i++)
	{
		printf("%5d", dtable[i].prev);
	}
	printf(" --- prev\n");

	for (int i = 1; i < G_SZ; i++)
	{
		printf("%5d", dtable[i].dist);
	}
	printf(" --- dist\n");

	for (int i = 1; i < G_SZ; i++)
	{
		printf("%5d", dtable[i].done);
	}
	printf(" --- done\n");
}

// s-->e 까지 가는 경로를 보여준다.
void show_path(int s, int e,DijkstraElement dtable[])
{
	int current = e;
	while (current != s)
	{
		printf("%d\n", current);
		current = dtable[current].prev;
	}
	printf("%d\n", s);
}

int main()
{
	DijkstraElement dtable[G_SZ];

	int graph[7][7] = {
		//0  1  2  3  4  5  6
		{-1,-1,-1,-1,-1,-1,-1}, // 0
		{-1,-1, 3,-1,15,-1,-1}, // 1
		{-1, 3,-1,30, 2,-1,-1}, // 2
		{-1,-1,30,-1,-1, 3, 4}, // 3
		{-1,15, 2,-1,-1, 1,-1}, // 4
		{-1,-1,-1, 3, 1,-1,20}, // 5
		{-1,-1,-1, 4,-1,20,-1}  // 6

	};

	// dtable 초기화 
	initDTable(dtable);

	// start = 1
	// start ver에서 직접 갈 수 있는 ver들에 대헤
	// dtable을 갱신 

	int start_ver = 1;

	dtable[start_ver].done = 1; // -----> 경로를 다 찾았다고 표시

	for (int i = 0; i < G_SZ; i++)
	{
		if (graph[start_ver][i] != -1) // start_ver에서 i까지 직접 가는 길이 있으면
		{
			dtable[i].dist = graph[start_ver][i];
			dtable[i].prev = start_ver;
		}
	}
	// dtable 에서 가장 짧은 거리를 가진 ver이면서 done = 0 인 ver를 찾는다.
	while (1)
	{
		int v = find_shortest_path_vertex(dtable);
		if (v == -1)
		{
			break;
		}

		dtable[v].done = 1; // v까지는 최단 경로가 결정

		// v르 통해서 갱신되는 경로가 더 짧은 ver를 찾아서
		// dtable 갱신
		for (int i = 0; i < G_SZ; i++)
		{
			if (graph[v][i] > -1 && dtable[i].done == 0)
			{   // i가지 최단 경로가 결정되지 않은 것들 중에서
				// v를 통해서 i까지 가는 길이 기존 알려진 길보다 더 짧으면서 

				// 이미 알려진 거리 > v를 통해가는 길
				if (dtable[i].dist > dtable[v].dist + graph[v][i])
				{
					dtable[i].dist = dtable[v].dist + graph[v][i];
					dtable[i].prev = v;  // ------> 주의
				}

			}
		}
	}

	show_dtable(dtable);

	printf("__________________\n");

	show_path(1, 6, dtable);  // 움직인 방향 역순 출력

	return 0;
}