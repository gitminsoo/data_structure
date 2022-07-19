//#include <stdio.h>
//
//void show_nums(int nums[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n");
//}
//
//void doswap(int nums[], int idxa, int idxb)
//{
//	// �ڸ��ٲ�
//	int temp = nums[idxa];
//	nums[idxa] = nums[idxb];
//	nums[idxb] = temp;
//}
//
//void quick_sort(int nums[], int start, int end)
//{
//	// ���⿡ ����� ���ϴ� sz=sizeof(nums)/sizeof(nums[0]) 
//	// �̷��� �ϸ� �迭 ������ �����ص� nums�� ��Ȯ�� ������ �Ұ���
//	// �׷��� sz�� main���� ���ֱ� 
//
//
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end) // start�� end ���� ũ�ų� ������ �׸� �ؾߵ� // Ż������
//	{
//		return;
//	}
//
//	while (low <= high) // �ΰ��� ������ while�� ������ �־��� �� ����, ���� ���ĵ� �������� ����
//	{
//		
//		while (nums[low] <= nums[pivot] &&low<=end)
//		{
//			low++;
//		}
//		while (nums[high] >= nums[pivot] && high >= start+1)
//		{
//			high--;
//		}
//
//		if (low < high)
//		{
//			doswap(nums, low, high);
//		}
//
//	}
//
//	// pivot�� �ڱ� �ڸ��� ã�ư����� �Ѵ�.
//	doswap(nums, pivot, high); // high�� �ٲ��ָ� ��
//
//	show_nums(nums, 13); // �ٲ�� ���� ���
//	// ���� 13 ��� �ֱ� ������ �Լ�����  realnum�� �μ� �߰��ϱ�
//
//	quick_sort(nums, start, high - 1); // �߰����� ������ ����Ʈ
//	quick_sort(nums, high + 1, end); // �������� ����Ʈ
//
//	// Ż�� ������ ���� ���ǵ� start�� end �� ������ return
//
//}
//
//int main()
//{
//	int nums[] = { 23,32,34,100,87,76,23,65,2,90,21,1,3 };
//
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	quick_sort(nums, 0, sz - 1);
//
//	printf("\n");
//
//	show_nums(nums, sz);
//}

//#include <stdio.h>
//
//#define NV 5
//
//void addedge(int graph[][NV], int v1, int v2)
//{
//	graph[v1][v2] = 1;  // ������ ������ ��Ÿ��
//	graph[v2][v1] = 1;
//
//}
//
//int main()
//{
//	int graph[NV][NV] = {0};
//	addedge(graph, 0, 1);
//	addedge(graph, 0, 2);
//	addedge(graph, 1, 2);
//	addedge(graph, 1, 3);
//	addedge(graph, 2, 3);
//	addedge(graph, 3, 4);
//	
//	for (int i = 0; i < NV; i++)
//	{
//		// 0���� ����� ���ؽ� Ȯ��
//		if (graph[0][i] == 1)
//		{
//			printf("%d ����Ǿ�����\n", i);
//		}
//	}
//}

#include <stdio.h>

#define NV 5

// visted[k]=1 �̸� �湮�Ѱ���
int visted[NV] = { 0 };

int stack[NV];
int top = -1;

int queue[NV];
int front = 0;
int rear = 0;

void enqueue(int v)
{
	if (front == (rear + 1) % NV)
	{
		return;
	}
	queue[rear] = v;
	rear = (rear + 1) % NV;
}

int dequeue()
{
	if (front == rear)
	{
		return -999;
	}
	int res = queue[front];
	front = (front + 1) % NV;
	return res;
}

int inqueue(int v)
{
	int i = front;

	while (i != rear)
	{
		if (queue[i] == v)
		{
			return 1;
		}

		i = (i + 1) % NV;
	}
	return 0;
}

int pop()
{
	if (top == -1)
	{
		return -999;
	}
	int res = stack[top];
	top--;
	return res;
}

void push(int v)
{
	if (top == NV - 1)
	{
		return;
	}
	top++;
	stack[top] = v;
}

// vertax v�� �̹� ������ 1 ������ 0
int inStack(int v)
{
	int i;
	for (i = 0; i <= top; i++)
	{
		if (stack[i] == v)
		{
			return 1;
		}
	}
	return 0;
}

void addEdge(int graph[][NV], int v1, int v2)
{
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;

}

// func pointer

void processAdjacentvertices(int graph[][NV], int v, int (*checkin)(int), void(*addfunc)(int))
{
	int i;
	for (i = 0; i < NV; i++)
	{
		if (graph[v][i] == 1)
		{
			if (visted[i] == 0 && (*checkin)(i) == 0)
			{
				(*addfunc)(i);
			}
		}
	}
}

void DepthFirstSearch(int graph[][NV], int startVertex)
{
	push(startVertex);
	while (1)
	{
		int v = pop();
		if (v == -999)
		{
			return;
		}
		printf("%d �湮\n", v);
		visted[v] = 1;
		processAdjacentvertices(graph, v,&inStack,&push);


	}
}

void BreathFirstSearch(int graph[][NV], int startVertex)
{
	enqueue(startVertex);
	while (1)
	{
		int v = dequeue();
		if (v == -999)
		{
			return;
		}
		printf("%d �湮\n", v);
		visted[v] = 1;
		processAdjacentvertices(graph, v,&inqueue,&enqueue);


	}
}

int main()
{
	int graph[NV][NV] = { 0 };
	
	addEdge(graph, 0, 1);
	addEdge(graph, 0,2);
	addEdge(graph, 1,2);
	addEdge(graph, 1,3);
	addEdge(graph, 2,3);
	addEdge(graph, 3,4);

	// 0�� ���� ���������� ����� ��� ���ؽ��� ã�ƶ�
	DepthFirstSearch(graph, 0);

	//BreathFirstSearch(graph, 4);

}