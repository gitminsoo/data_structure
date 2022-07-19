#include <stdio.h>
#define NV 5

void addEdge(int graph[][NV], int v1, int v2, int we)
{
	graph[v1][v2] = we;
	graph[v2][v1] = we;
}

void prim_MST(int graph[][NV], int start)
{
	int visited[NV] = { 0 };
	visited[start] = 1;

	for (int cnt = 0; cnt < NV - 1; cnt++)
	{
		int visitied_ver = -1;
		int nonvisitied_ver = -1;
		int mindist = 9999;

		for (int i = 0; i < NV; i++)
		{
			if (visited[i] == 1)
			{
				for (int j = 0; j < NV; j++)       // j가 0부터인거 신경쓰기
				{
					if (graph[i][j] && visited[j] == 0 && graph[i][j] < mindist)
					{
						visitied_ver = i;
						nonvisitied_ver = j;
						mindist = graph[i][j];
					}
				}
			}

		}

		printf("%d ---- %d\n", visitied_ver, nonvisitied_ver);
		visited[nonvisitied_ver] = 1;

	}
}

void kruskal_MST(int graph[][NV])
{
	int family[NV] = { 0,1,2,3,4 };

	for (int cnt = 0; cnt < NV - 1; cnt++)
	{
		int v1 = -1;
		int v2 = -1;
		int mindist = 9999;
		for (int i = 0; i <= NV; i++)
		{
			for (int j = i + 1; j < NV; j++)
			{
				if (graph[i][j] && mindist > graph[i][j] && family[i] != family[j])
				{
					v1 = i;
					v2 = j;
					mindist = graph[i][j];
				}
			}
		}
		printf("%d --- %d\n", v1, v2);
		int old_fam = family[v2];
		int new_fam = family[v1];

		for (int k = 0; k < NV; k++)
		{
			if (family[k] == old_fam)
			{
				family[k] = new_fam;
			}
		}
	}

}


int main()
{
	int graph[NV][NV] = { 0 };

	addEdge(graph, 0, 1, 100);  // 0-->1 edge, weight=100
	addEdge(graph, 0, 2, 10);
	addEdge(graph, 1, 2, 40);
	addEdge(graph, 1, 3, 50);
	addEdge(graph, 2, 3, 1);
	addEdge(graph, 3, 4, 10);


	// MST by prim
	// start ver = 0 ,prim으로 찾는다
	kruskal_MST(graph);

	// MST by kruskal
	//perform_MST_kruskal(graph);

}