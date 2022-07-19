#include <stdio.h>

#define HL 5
int heap[HL];

int heapsize = 0;

void enqueue(int v)
{
	if (heapsize == (HL - 1))
	{
		return;
	}
	heapsize++;
	heap[heapsize] = v;

	int me = heapsize;
	int parent = heapsize / 2;

	while (1)
	{
		if (me == 1)
		{
			return;
		}
		if (heap[parent] > heap[me])
		{
			return;
		}
		else
		{
			int temp = heap[parent];
			heap[parent] = heap[me];
			heap[me] = temp;

			me = parent;
			parent = me / 2;
		}
	}
}

int findreplacer(int me)
{
	int left = me * 2;
	int right = me * 2 + 1;

	if (heapsize < left)
	{
		return 0;
	}
	else if (heapsize < right)
	{
		return left;
	}
	else if (heap[left] > heap[right])
	{
		return left;
	}
	else if (heap[left] < heap[right])
	{
		return right;
	}
}

int dequeue()
{
	if (heapsize == 0)
	{
		return -999;
	}
	int res = heap[1];
	heap[1] = heap[heapsize];
	heapsize--;

	int me = 1;
	while (1)
	{
		int re = findreplacer(me);
		if (re == 0)
		{
			return res;
		}
		if (heap[me] > heap[re])
		{
			return res;
		}
		if (heap[me] < heap[re])
		{
			int temp = heap[me];
			heap[me] = heap[re];
			heap[re] = temp;

			me = re;
		}
	}

}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(10);
	enqueue(3);

	for (int i = 0; i < 4; i++) {
		printf("%d\n", dequeue());
	}
}