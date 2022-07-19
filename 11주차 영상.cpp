// minimum spanning tree
// 
// MST
// 
// weighted graph
// 예를들어 
// 5개의 버텍스 연결은 4개의 엣지만 있어도 가능
// 직접연결은 안되지만 
// 간접적으로 연결도 포함 
// 
// 최소 엣지 갯수로 연결 + weighted 포함
// 
// 다룰 알고리즘 2가지
// 1. prim
// 2. kruskal 
// 
// 크루스칼 --> greedy 알고리즘
// greedy 알고리즘 -> 가장 직관적으로 하는거
// 가장 작은 weight으로 연결하며 만들어감
// 근데, 엣지 마음대로 작은거만 연결 시 안되는경우 생김
// --> 포함이 암되는 버텍스 생김  --> 넣으면 안되는 버텍스를 넣는 상황이 생김
// 
// 크루스칼 알고리즘 핵심 ==> 사이클이 형성되지 않게 해야함
// 어떻게 확인??
// 좀이따 설명해줌
// 
// 
// 
// 프림알고리즘
// 임의의 버텍스로 시작 
// 그 버텍스에 연결된 엣지중 작은 엣지로 이동
// 그 둘을 group으로 묶어서 그중 가장 작은애로 이동
// 그 친구까지 셋을 연결 
// 반복,,,
// visted group 이라 표현 가능
// 이미 방문한 vertex를 visited group에 추가
// startver를 visited에 추가 연결되는 ver를 visted추가
// 
// 총 ver수 -1 이 최소엣지 갯수 이므로 
// ver-1이 되면 스탑
// visited 를 배열로 구현
//

// kruskal

// 가장 짧은 edge선택
// cycle이 생성되지 않으면 edge 출력
// #vertex - 1 번 반복
// 
// cycle 생성 여부
// - famillt array 사용
// 연결시마다 동일 family 소속으로 변경
//

#include <stdio.h>

#define NV 5

void addEdge(int graph[][NV], int v1, int v2, int weight)
{
	graph[v1][v2] = weight;  // 0보다 크면 경로가 있고 웨이트가 해당 수이다.
	graph[v2][v1] = weight;
}

void perform_MST_Prim(int graph[][NV], int sVertex)
{
	// visited ver array
	int visited[NV] = { 0 }; // MST를 구성하는 ver에 포함되었는지 표시 1이면 포함 0이면 미포함

	visited[sVertex] = 1; 

	// 찾아야 하는 edge 갯수는 NV - 1
	for (int i = 0; i < NV - 1; i++) // NV - 1 개의 edge를 찾는다
	{
		int minDist = 99999;
		int visted_ver = -1;
		int nonvisited_ver = -1;
	
			// visited --> non-visited 가장 작은 weight
			for (int j = 0; j < NV; j++)
			{	// find visited 
				if (visited[j] == 1)
				{
					for (int k = 0; k < NV; k++)
					{
						if (visited[k] == 0) // 방문하지 않은 애들중에서 j->k
						{
							if ((graph[j][k] > 0) && graph[j][k] < minDist)      // j->k edge가 있고 지금까지 알려진 weight 보다 작을때
							{
								minDist = graph[j][k];
								visted_ver = j;
								nonvisited_ver = k;
							}
						}
					}
				}
			}
		

		// MST의 새롭게 추가될 edge를 출력
		printf("%d --- %d\n", visted_ver, nonvisited_ver);
		// 새롭게 들어온 non이 이제 우리 식구다.
		visited[nonvisited_ver] = 1;
	}
}

void perform_MST_kruskal(int graph[][NV])
{
	int family[NV] = { 0,1,2,3,4 };

	// NV-1 만큼의 edge를 찾는다
	for (int cnt = 0; cnt < NV - 1; cnt++)
	{
		int v1 = -1;
		int v2 = -1;
		int minDist = 9999;

		// 가장 weight 가 작은 edge찾아서 MST에 포함시킨다.
		for (int i = 0; i < NV; i++)
		{
			for (int j = i + 1; j < NV; j++)
			{
				// 1. 경로가 있고
				// 2. 같은 family가 있고
				// 3. 지금까지 알려진 minDis보다 짧은 edge
				if (graph[i][j] && family[i] != family[j] && minDist > graph[i][j])
				{
					minDist = graph[i][j];
					v1 = i;
					v2 = j;
				}
			}
		}

		// 가장 짧은 edge를 찾았으므로 
		printf("%d --- %d\n", v1, v2);
		// v1,v2 가문의 결혼
		// 항상 i보다 j가 큼 위의 for문ㅇ에 따라
		int old_family = family[v2];
		int new_family = family[v1];
		// 임시 변수 지정한 이유는 
		// k가 v2일 시 그 뒤부터 진행이 안되므로
		// 임시변수 지정한거

		for (int k = 0; k < NV; k++)
		{
			if (family[k] == old_family)
			{
				family[k] = new_family;
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
	 //perform_MST_Prim(graph, 0);

	// MST by kruskal
	perform_MST_kruskal(graph);

}


