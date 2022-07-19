#include <stdio.h>

#define NV 5

int visited[NV] = { 0 };

int stack[NV];
int top = -1;

int queue[NV];
int front = 0;
int rear = 0;

void push(int v)
{
	if (top == (NV - 1))
	{
		return;
	}
	top++;
	stack[top] = v;
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
int instack(int v)
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

void addEdge(int graph[][NV], int v1, int v2)
{
	graph[v1][v2] = 1;
	graph[v2][v1] = 1;

}

void pAV(int graph[][NV], int v, int (*check)(int), void (*add)(int))
{
	int i;
	for (i = 0; i < NV; i++)
	{
		if (graph[i][v])
		{
			if ((*check)(i) == 0 && visited[i] == 0)
			{
				(*add)(i);
			}
		}
	}
}

void DFS(int graph[][NV], int start)
{
	push(start);
	while (1)
	{
		int v = pop();
		if (v == -999)
		{
			return;
		}
		printf("%d ", v);
		visited[v] = 1;
		pAV(graph, v, &instack, &push);
	}
}

void BFS(int graph[][NV], int start)
{
	enqueue(start);
	while (1)
	{
		int v = dequeue();
		if (v == -999)
		{
			return;
		}
		printf("%d ", v);
		visited[v] = 1;
		pAV(graph, v, &inqueue, &enqueue);
	}
}

int main()
{
	int graph[NV][NV] = { 0 };

	addEdge(graph, 0, 1);
	addEdge(graph, 0, 2);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 3);
	addEdge(graph, 2, 3);
	addEdge(graph, 3, 4);

	// 0과 직접 간접적으로 연결된 모든 버텍스를 찾아라
	BFS(graph, 0);

	//BreathFirstSearch(graph, 4);

}