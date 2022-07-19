// Dijkstra Algorithm
//

#include <stdio.h>

#define G_SZ 7

typedef struct {
	int prev; // ������ ���ؽ� ��ȣ
	int dist; // ������������ �Ÿ�
	int done; // �ִܰŸ��� ã���� 1 �ƴϸ� 0
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

// dtable���� dist�� ���� ª�� done �� 0�� verã��
// �� ��ȣ�� ��ȯ
// ���� ��� ver�� done �� 1�̸� -1 ��ȯ ==> Dijkstra end
int find_shortest_path_vertex(DijkstraElement dtable[])
{
	int ver_idx = -1;    // �ִ� �Ÿ� ���� ver
	int ver_dist = 9999; // �� ver�� �ִܰŸ�

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

// s-->e ���� ���� ��θ� �����ش�.
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

	// dtable �ʱ�ȭ 
	initDTable(dtable);

	// start = 1
	// start ver���� ���� �� �� �ִ� ver�鿡 ����
	// dtable�� ���� 

	int start_ver = 1;

	dtable[start_ver].done = 1; // -----> ��θ� �� ã�Ҵٰ� ǥ��

	for (int i = 0; i < G_SZ; i++)
	{
		if (graph[start_ver][i] != -1) // start_ver���� i���� ���� ���� ���� ������
		{
			dtable[i].dist = graph[start_ver][i];
			dtable[i].prev = start_ver;
		}
	}
	// dtable ���� ���� ª�� �Ÿ��� ���� ver�̸鼭 done = 0 �� ver�� ã�´�.
	while (1)
	{
		int v = find_shortest_path_vertex(dtable);
		if (v == -1)
		{
			break;
		}

		dtable[v].done = 1; // v������ �ִ� ��ΰ� ����

		// v�� ���ؼ� ���ŵǴ� ��ΰ� �� ª�� ver�� ã�Ƽ�
		// dtable ����
		for (int i = 0; i < G_SZ; i++)
		{
			if (graph[v][i] > -1 && dtable[i].done == 0)
			{   // i���� �ִ� ��ΰ� �������� ���� �͵� �߿���
				// v�� ���ؼ� i���� ���� ���� ���� �˷��� �溸�� �� ª���鼭 

				// �̹� �˷��� �Ÿ� > v�� ���ذ��� ��
				if (dtable[i].dist > dtable[v].dist + graph[v][i])
				{
					dtable[i].dist = dtable[v].dist + graph[v][i];
					dtable[i].prev = v;  // ------> ����
				}

			}
		}
	}

	show_dtable(dtable);

	printf("__________________\n");

	show_path(1, 6, dtable);  // ������ ���� ���� ���

	return 0;
}