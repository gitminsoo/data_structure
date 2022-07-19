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
//	// 자리바꿈
//	int temp = nums[idxa];
//	nums[idxa] = nums[idxb];
//	nums[idxb] = temp;
//}
//
//void quick_sort(int nums[], int start, int end)
//{
//	// 여기에 사이즈를 구하는 sz=sizeof(nums)/sizeof(nums[0]) 
//	// 이렇게 하면 배열 접근은 가능해도 nums의 정확한 접근은 불가능
//	// 그래서 sz는 main에서 해주기 
//
//
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end) // start가 end 보다 크거나 같으면 그만 해야됨 // 탈출조건
//	{
//		return;
//	}
//
//	while (low <= high) // 두개의 조건을 while문 안으로 넣어줄 수 있음, 둘이 겹쳐도 진행임을 생각
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
//	// pivot이 자기 자리를 찾아가도록 한다.
//	doswap(nums, pivot, high); // high랑 바꿔주면 됨
//
//	show_nums(nums, 13); // 바뀌는 과정 출력
//	// 여가 13 상수 넣기 싫으면 함수내에  realnum의 인수 추가하기
//
//	quick_sort(nums, start, high - 1); // 중간기준 왼쪽의 퀵소트
//	quick_sort(nums, high + 1, end); // 오른쪽의 퀵소트
//
//	// 탈출 조건은 위에 쓸건데 start와 end 가 같으면 return
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
//	graph[v1][v2] = 1;  // 양쪽의 영결을 나타냄
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
//		// 0번에 연결된 버텍스 확인
//		if (graph[0][i] == 1)
//		{
//			printf("%d 연결되어있음\n", i);
//		}
//	}
//}

#include <stdio.h>

#define NV 5

// visted[k]=1 이면 방문한거임
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

// vertax v가 이미 있으면 1 없으면 0
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
		printf("%d 방문\n", v);
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
		printf("%d 방문\n", v);
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

	// 0과 직접 간접적으로 연결된 모든 버텍스를 찾아라
	DepthFirstSearch(graph, 0);

	//BreathFirstSearch(graph, 4);

}