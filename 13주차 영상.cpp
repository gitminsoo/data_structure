// ford algorithm
// ��� ���ؽ��� �ִ� �Ÿ� 

#include <stdio.h>
#include <string.h>

#define G_SZ 7

int main()
{
	int graph[G_SZ][G_SZ]
	{
		{9999,4,1,9999,9999,9999,10},
		{4,9999,3,9999,15,9999,9999},
		{1,3,9999,30,2,9999,9999},
		{9999,9999,30,9999,9999,3,4},
		{9999,15,2,9999,9999,1,9999},
		{9999,9999,9999,3,1,9999,20},
		{10,9999,9999,4,9999,20,9999}
	};

	int atable[G_SZ][G_SZ] = { 0 };

	memcpy(atable, graph, sizeof(int) * G_SZ * G_SZ);
	for (int i = 0; i < G_SZ; i++)
	{
		atable[i][i] = 0;
	}
	for (int k = 0; k < G_SZ; k++)
	{
		for (int i = 0; i < G_SZ; i++)
		{
			for (int j = 0; j < G_SZ; j++)
			{
				if (atable[i][j] > atable[i][k] + atable[k][j])
				{
					atable[i][j] = atable[i][k] + atable[k][j];
				}
			}
		}
	}

	for (int i = 0; i < G_SZ; i++)
	{
		for (int j = 0; j < G_SZ; j++)
		{
			printf("%5d ", atable[i][j]);
		}
		printf("\n");
	}

	return 0;
}

// topological_sort
// ���⼺�� ������ ���� ������ ������
// 0�� ������ ���� 2���� ��´�... �̷���
// ���������� �ֳ� ���� �Ǻ��ϸ� ���ļ� ���踦 ������ ����
// ���� ����
// ver���忡�� �ڽ����� ������ edge �� 
// indegree �� 0�� ���ؽ��� �������� �ϸ� ����
//

#include <stdio.h>

#define NV 6

void initIndegreeTable(int graph[][NV], int indegree_table[])
{
	for (int i = 0; i < NV; i++)
	{
		int indegree_cnt = 0;
		for (int j = 0; j < NV; j++)
		{
			if (graph[j][i] > 0) // i�� ������ ������ �����ϴϱ�
			{
				indegree_cnt++;
			}
		}
		indegree_table[i] = indegree_cnt;
	}
}

int getIdxOfIndegreeZero(int indegree_table[])
{
	for (int i = 0; i < NV; i++)
	{
		if (indegree_table[i] == 0)
		{
			return i;
		}
	}
	return -1;
}

void UpdateIndegreeTable(int idx, int indegree_Table[], int graph[][NV])
{
	for (int i = 0; i < NV; i++)
	{
		if (graph[idx][i] > 0)
		{
			indegree_Table[i]--;
			// indegree_Table[i]-= 1;

		}
	}
}

int main()
{
	// indirecr edge�� ��Ī����� �ƴ�
	int graph[NV][NV] = {
		{0,0,1,1,0,0},
		{0,0,0,1,1,0},
		{0,0,0,0,0,0},
		{0,0,1,0,0,1},
		{0,0,0,1,0,1},
		{0,0,0,0,0,0}
	};

	int indegree_table[NV] = { 0 };

	initIndegreeTable(graph, indegree_table);

	while (1)
	{
		int idx = getIdxOfIndegreeZero(indegree_table);
		if (idx == -1)
		{
			break;
		}
		printf("%d -- >", idx);
		indegree_table[idx] = -100;

		UpdateIndegreeTable(idx, indegree_table, graph);
	}
}