#include <stdio.h>

#define NV 5

void addEdge(int graph[][NV], int v1, int v2, int weight)
{
	graph[v1][v2] = weight;
	graph[v2][v1] = weight;
}

void MST_prim(int graph[][NV], int start)
{
	int visited[NV] = { 0 };
	visited[start] = 1;

	for (int i = 0; i < NV - 1; i++)
	{
		int minD = 9999;
		int visited_ver = -1;
		int non_visited_ver = -1;

		for (int j = 0; j < NV; j++)
		{
			if (visited[j] == 1)
			{
				for (int k = 0; k < NV; k++)
				{
					if (visited[k] == 0)
					{
						if ((graph[j][k] > 0) && (graph[j][k] < minD))
						{
							minD = graph[j][k];
							visited_ver = j;
							non_visited_ver = k;
						}
					}
				}
			}
		}

		printf("%d -- %d\n", visited_ver, non_visited_ver);
		visited[non_visited_ver] = 1;
	}
}

void MST_kruskal(int graph[][NV])
{
	int family[NV] = { 0,1,2,3,4 };

	for (int cnt = 0; cnt < NV - 1; cnt++)
	{
		int v1 = -1;
		int v2 = -1;
		int minD = 9999;

		for (int i = 0; i < NV; i++)
		{
			for (int j = i + 1; j < NV; j++)
			{
				if (graph[i][j] && family[i] != family[j] && minD > graph[i][j])
				{
					minD = graph[i][j];
					v1 = i;
					v2 = j;
				}
			}
		}

		printf("%d -- %d\n", v1, v2);

		int oldfam = family[v2];
		int newfam = family[v1];

		for (int k = 0; k < NV; k++)
		{
			if (family[k] == oldfam)
			{
				family[k] = newfam;
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
	MST_prim(graph,0);
}

//#include <stdio.h>
//
//#pragma warning (disable:4996)
//
//#define NV 7
//
//int v_array[NV];
//
//int visited[NV] = { 0 };
//
//int stack[NV];
//int top = -1;
//
//int queue[NV];
//int rear = 0;
//int front = 0;
//
//
//void addedge(int graph[][NV], int v1, int v2)
//{
//	graph[v1][v2] = 1;
//	graph[v2][v1] = 1;
//}
//
//void push(int v)
//{
//	if (top == (NV - 1))
//	{
//		return;
//	}
//	top++;
//	stack[top] = v;
//}
//int pop()
//{
//	if (top == -1)
//	{
//		return -999;
//	}
//	int res = stack[top];
//	top--;
//	return res;
//}
//int instack(int v)
//{
//	int i;
//	for (i = 0; i <= top; i++)
//	{
//		if (stack[i] == v)
//		{
//			return 1;
//		}
//	}
//	return 0;
//}
//
//void enqueue(int v)
//{
//	if ((rear + 1) % NV == front)
//	{
//		return;
//	}
//	queue[rear] = v;
//	rear = (rear + 1) % NV;
//}
//int dequeue()
//{
//	if (front == rear)
//	{
//		return -999;
//	}
//	int res = queue[front];
//	front = (front + 1) % NV;
//	return res;
//}
//int inqueue(int v)
//{
//	int i = front;
//	while (i != rear)
//	{
//		if (queue[i] == v)
//		{
//			return 1;
//		}
//		i = (i + 1) % NV;
//	}
//	return 0;
//}
//
//void process(int graph[][NV], int v, int (*check_v)(int), void(*add_v)(int))
//{
//	int i;
//	for (i = 0; i < NV; i++)
//	{
//		if (graph[v][i] == 1)
//		{
//			if (visited[i] == 0 && (*check_v)(i) == 0)
//			{
//				(*add_v)(i);
//			}
//		}
//	}
//}
//
//void DFS(int graph[][NV], int start)
//{
//	int cnt = 0;
//	push(start);
//	while (1)
//	{
//		int v = pop();
//		if (v == -999)
//		{
//			return;
//		}
//		v_array[cnt] = v;
//		visited[v] = 1;
//		process(graph, v, &instack, &push);
//		cnt++;
//	}
//}
//
//void BFS(int graph[][NV], int start)
//{
//	int cnt = 0;
//	enqueue(start);
//	while (1)
//	{
//		int v = dequeue();
//		if (v == -999)
//		{
//			return;
//		}
//		v_array[cnt] = v;
//		visited[v] = 1;
//		process(graph, v, inqueue, enqueue);
//		cnt++;
//	}
//}
//
//void quick_sort(int nums[], int start, int end)
//{
//	if (start >= end)
//	{
//		return;
//	}
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	while (low <= high)
//	{
//		while (nums[low] <= nums[pivot] && low <= end)
//		{
//			low++;
//		}
//		while (nums[high] >= nums[pivot] && high >= start + 1)
//		{
//			high--;
//		}
//		if (low < high)
//		{
//			int temp = nums[low];
//			nums[low] = nums[high];
//			nums[high] = temp;
//		}
//	}
//
//	int temp = nums[pivot];
//	nums[pivot] = nums[high];
//	nums[high] = temp;
//
//	quick_sort(nums, start, high - 1);
//	quick_sort(nums, high + 1, end);
//}
//
//void bubble_sort(int nums[], int start, int end)
//{
//	for (int i = 0; i <= end; i++)
//	{
//		for (int j = 0; j < end - i; j++)
//		{
//			if (nums[j] > nums[j + 1])
//			{
//				int temp = nums[j];
//				nums[j] = nums[j + 1];
//				nums[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int graph[NV][NV] = { 0 };
//
//	addedge(graph, 0, 1);
//	addedge(graph, 0, 2);
//	addedge(graph, 1, 2);
//	addedge(graph, 1, 3);
//	addedge(graph, 2, 3);
//	addedge(graph, 4, 5);
//	addedge(graph, 3, 6);
//	addedge(graph, 6, 5);
//
//	int nums[] = { 5,9,1,0,3,7,6 };
//	bubble_sort(nums, 0, 6);
//
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//
//	DFS(graph, 0);
//
//	quick_sort(v_array, 0, NV - 1);
//
//	for (int i = 0; i < NV; i++)
//	{
//		//printf("%d ", v_array[i]);
//	}
//
//}
