#include <stdio.h>

#define NV 7

typedef struct {
	int prev;
	int dist;
	int done;
} node;

void init(node map[])
{
	for (int i = 0; i < NV; i++)
	{
		map[i].dist = 9999;
		map[i].done = 0;
		map[i].prev = -1;
	}
}

int findshort(node map[])
{
	int ver = -1;
	int mindist = 9999;

	for (int i = 0; i < NV; i++)
	{
		if (map[i].done == 0 && map[i].dist < mindist)
		{
			ver = i;
			mindist = map[i].dist;
		}
	}
	return ver;
}

void show(int s, int e, node map[])
{
	int cur = e;
	while (cur != s)
	{
		printf("%d ", cur);
		cur = map[cur].prev;
	}
	printf("%d\n", s);
}

int main()
{
	node map[NV];

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

	init(map);

	int start = 1;
	int end = 6;

	map[start].done = 1;
	map[start].dist = 0; // 

	for (int i = 0; i < NV; i++)
	{
		if (graph[i][start] > 0)
		{
			map[i].dist = graph[start][i];
			map[i].prev = start;
		}

	}

	while (1)
	{
		int v = findshort(map);
		if (v == -1)
		{
			break;
		}

		map[v].done = 1;

		for (int i = 0; i < NV; i++)
		{
			if (graph[v][i] > -1 && map[i].done == 0)
			{
				if (map[i].dist > map[v].dist + graph[v][i])
				{
					map[i].dist = map[v].dist + graph[v][i];
					map[i].prev = v;
				}
			}
		}
	}

	show(start, end, map);

}