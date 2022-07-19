#include <stdio.h>

#pragma warning (disable:4996)

#define H_S 8
int heap[H_S];
int heapsiz = 0;

void enqueue(int _data)
{
	if (heapsiz == (H_S - 1))
	{
		printf("full\n");
		return;
	}

	heapsiz++;
	heap[heapsiz] = _data;

	int me = heapsiz;
	int parent = me / 2;

	while (1)
	{
		if (me == 1)
		{
			return;
		}
		if (heap[me] > heap[parent])
		{
			int res = heap[me];
			heap[me] = heap[parent];
			heap[parent] = res;

			me = parent;
			// 바뀌는 parent를 캐치
			parent = me / 2;
		}
		if (heap[me] < heap[parent])
		{
			return;
		}
	}
}

int findReplacer(int _me)
{
	int left = _me * 2;
	int right = _me * 2 + 1;

	if (heapsiz < left)
	{
		return 0;
	}
	if (heapsiz < right)
	{
		return left;
	}
	if (heap[left] > heap[right])
	{
		return left;
	}
	if (heap[left] < heap[right])
	{
		return right;
	}

}

int dequeue()
{
	if (heapsiz == 0)
	{
		printf("empty\n");
		return 0;
	}

	int res = heap[1];
	heap[1] = heap[heapsiz];
	heapsiz--;

	int me = 1;

	while (1)
	{
		int replacer = findReplacer(me);

		if (replacer == 0)
		{
			return res;
		}
		if (heap[replacer] < heap[me])
		{
			return res;
		}
		if (heap[replacer] > heap[me])
		{
			int temp = heap[me];
			heap[me] = heap[replacer];
			heap[replacer] = temp;

			me = replacer;
		}
	}


}

void delqueue(int _data)
{
	if (heapsiz == 0)
	{
		return;
	}
	int i = 0;


	for (i = 0; i < heapsiz; i++)
	{
		if (heap[i] == _data)
		{
			break;
		}
	}

	heap[i] = heap[heapsiz];
	heapsiz--;

	int me = i;

	while (1)
	{
		int replacer = findReplacer(me);
		if (replacer == 0)
		{
			return;
		}
		if (heap[me] < heap[replacer])
		{
			int res = heap[me];
			heap[me] = heap[replacer];
			heap[replacer] = res;

			me = replacer;
		}
		if (heap[me] > heap[replacer])
		{
			return;
		}
	}

}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		int data = 0;
		scanf("%d", &data);
		enqueue(data);
	}
	scanf("%d", &n);
	delqueue(n);

	for (i = 1; i <= heapsiz; i++)
	{
		printf("%d ", heap[i]);
	}

}

//#include <stdio.h>
//
//#pragma warning(disable:4996)
//
//#define H_L 10
//int heap[H_L];
//int h_size = 0;
//
//void enqueue(int _data)
//{
//	if (h_size == (H_L - 1))
//	{
//		printf("full queue\n");
//		return;
//	}
//	
//	h_size++;
//	heap[h_size] = _data;
//
//	int me = h_size;
//	int parent = me / 2;
//	
//	while (1)
//	{
//		if (me == 1)
//		{
//			return;
//		}
//		if (heap[me] < heap[parent])
//		{
//			return;
//		}
//		if (heap[me] > heap[parent])
//		{
//			int res = heap[me];
//			heap[me] = heap[parent];
//			heap[parent] = heap[me];
//
//			me = parent;
//			parent = me / 2;
//		}
//	}
//}
//
//int findReplacer(int _me)
//{
//	int left = _me * 2;
//	int right = _me * 2 + 1;
//
//	if (h_size < left)
//	{
//		return 0;
//	}
//	if (h_size < right)
//	{
//		return left;
//	}
//	if (heap[left] > heap[right])
//	{
//		return left;
//	}
//	if (heap[left] < heap[right])
//	{
//		return right;
//	}
//}
//
//int dequeue()
//{
//	if (h_size == 0)
//	{
//		printf("empty\n");
//		return -999;
//	}
//
//	int res = heap[1];
//	heap[1] = heap[h_size];
//	h_size--;
//
//	int me = 1;
//
//	while (1)
//	{
//		int replacer = findReplacer(me);
//
//		if (replacer == 0)
//		{
//			return res;
//		}
//		if (heap[me] > heap[replacer])
//		{
//			return res;
//		}
//		if (heap[me] < heap[replacer])
//		{
//			int temp = heap[me];
//			heap[me] = heap[replacer];
//			heap[replacer] = temp;
//
//			me = replacer;
//		}
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int data = 0;
//		scanf("%d", &data);
//		enqueue(data);
//	}
//
//	dequeue();
//
//	for (i = 0; i < 6; i++)
//	{
//		printf("%d ", heap[i+1]);
//	}
//
//}