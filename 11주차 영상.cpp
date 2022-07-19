// minimum spanning tree
// 
// MST
// 
// weighted graph
// ������� 
// 5���� ���ؽ� ������ 4���� ������ �־ ����
// ���������� �ȵ����� 
// ���������� ���ᵵ ���� 
// 
// �ּ� ���� ������ ���� + weighted ����
// 
// �ٷ� �˰��� 2����
// 1. prim
// 2. kruskal 
// 
// ũ�罺Į --> greedy �˰���
// greedy �˰��� -> ���� ���������� �ϴ°�
// ���� ���� weight���� �����ϸ� ����
// �ٵ�, ���� ������� �����Ÿ� ���� �� �ȵǴ°�� ����
// --> ������ �ϵǴ� ���ؽ� ����  --> ������ �ȵǴ� ���ؽ��� �ִ� ��Ȳ�� ����
// 
// ũ�罺Į �˰��� �ٽ� ==> ����Ŭ�� �������� �ʰ� �ؾ���
// ��� Ȯ��??
// ���̵� ��������
// 
// 
// 
// �����˰���
// ������ ���ؽ��� ���� 
// �� ���ؽ��� ����� ������ ���� ������ �̵�
// �� ���� group���� ��� ���� ���� �����ַ� �̵�
// �� ģ������ ���� ���� 
// �ݺ�,,,
// visted group �̶� ǥ�� ����
// �̹� �湮�� vertex�� visited group�� �߰�
// startver�� visited�� �߰� ����Ǵ� ver�� visted�߰�
// 
// �� ver�� -1 �� �ּҿ��� ���� �̹Ƿ� 
// ver-1�� �Ǹ� ��ž
// visited �� �迭�� ����
//

// kruskal

// ���� ª�� edge����
// cycle�� �������� ������ edge ���
// #vertex - 1 �� �ݺ�
// 
// cycle ���� ����
// - famillt array ���
// ����ø��� ���� family �Ҽ����� ����
//

#include <stdio.h>

#define NV 5

void addEdge(int graph[][NV], int v1, int v2, int weight)
{
	graph[v1][v2] = weight;  // 0���� ũ�� ��ΰ� �ְ� ����Ʈ�� �ش� ���̴�.
	graph[v2][v1] = weight;
}

void perform_MST_Prim(int graph[][NV], int sVertex)
{
	// visited ver array
	int visited[NV] = { 0 }; // MST�� �����ϴ� ver�� ���ԵǾ����� ǥ�� 1�̸� ���� 0�̸� ������

	visited[sVertex] = 1; 

	// ã�ƾ� �ϴ� edge ������ NV - 1
	for (int i = 0; i < NV - 1; i++) // NV - 1 ���� edge�� ã�´�
	{
		int minDist = 99999;
		int visted_ver = -1;
		int nonvisited_ver = -1;
	
			// visited --> non-visited ���� ���� weight
			for (int j = 0; j < NV; j++)
			{	// find visited 
				if (visited[j] == 1)
				{
					for (int k = 0; k < NV; k++)
					{
						if (visited[k] == 0) // �湮���� ���� �ֵ��߿��� j->k
						{
							if ((graph[j][k] > 0) && graph[j][k] < minDist)      // j->k edge�� �ְ� ���ݱ��� �˷��� weight ���� ������
							{
								minDist = graph[j][k];
								visted_ver = j;
								nonvisited_ver = k;
							}
						}
					}
				}
			}
		

		// MST�� ���Ӱ� �߰��� edge�� ���
		printf("%d --- %d\n", visted_ver, nonvisited_ver);
		// ���Ӱ� ���� non�� ���� �츮 �ı���.
		visited[nonvisited_ver] = 1;
	}
}

void perform_MST_kruskal(int graph[][NV])
{
	int family[NV] = { 0,1,2,3,4 };

	// NV-1 ��ŭ�� edge�� ã�´�
	for (int cnt = 0; cnt < NV - 1; cnt++)
	{
		int v1 = -1;
		int v2 = -1;
		int minDist = 9999;

		// ���� weight �� ���� edgeã�Ƽ� MST�� ���Խ�Ų��.
		for (int i = 0; i < NV; i++)
		{
			for (int j = i + 1; j < NV; j++)
			{
				// 1. ��ΰ� �ְ�
				// 2. ���� family�� �ְ�
				// 3. ���ݱ��� �˷��� minDis���� ª�� edge
				if (graph[i][j] && family[i] != family[j] && minDist > graph[i][j])
				{
					minDist = graph[i][j];
					v1 = i;
					v2 = j;
				}
			}
		}

		// ���� ª�� edge�� ã�����Ƿ� 
		printf("%d --- %d\n", v1, v2);
		// v1,v2 ������ ��ȥ
		// �׻� i���� j�� ŭ ���� for������ ����
		int old_family = family[v2];
		int new_family = family[v1];
		// �ӽ� ���� ������ ������ 
		// k�� v2�� �� �� �ں��� ������ �ȵǹǷ�
		// �ӽú��� �����Ѱ�

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
	// start ver = 0 ,prim���� ã�´�
	 //perform_MST_Prim(graph, 0);

	// MST by kruskal
	perform_MST_kruskal(graph);

}


