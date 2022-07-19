// max heap

//#include <stdio.h>
//#pragma warning(disable:4996)
//
//#define H_S 10
//int heapsize = 0;
//int heap[H_S];
//
//void enqueue(int _data)
//{
//	if (heapsize == (H_S - 1))
//	{
//		return;
//
//	}
//
//	heapsize++;
//	heap[heapsize] = _data;
//
//	int me = heapsize;
//	int parent = heapsize / 2;
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
//			heap[parent] = res;
//
//			me = parent;
//			parent = me / 2;
//		}
//	}
//}
//
//int findreplacer(int _me)
//{
//	int left = _me * 2;
//	int right = _me * 2 + 1;
//
//	if (heapsize < left)
//	{
//		return 0;
//	}
//	if (heapsize < right)
//	{
//		return left;
//	}
//	if (heap[left] < heap[right])
//	{
//		return right;
//	}
//	if (heap[left] > heap[right])
//	{
//		return left;
//	}
//
//}
//
//int dequeue()
//{
//	if (heapsize == 0)
//	{
//		return -999;
//	}
//
//	int res = heap[1];
//	heap[1] = heap[heapsize];
//	heapsize--;
//
//	int me = 1;
//
//	while (1)
//	{
//		int re = findreplacer(me);
//
//		if (me == 0)
//		{
//			return res;
//		}
//		if (heap[me] > heap[re])
//		{
//			return res;
//		}
//		if (heap[re] > heap[me])
//		{
//			int res = heap[me];
//			heap[me] = heap[re];
//			heap[re] = res;
//
//			me = re;
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
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", dequeue());
//	}
//
//}

//#include <stdio.h>
//
//void doselectionsort(int _data[], int _sz)
//{
//	int k = 0;
//	int temp = 0;
//	int i;
//	int least = 0;
//
//	for (k = 0; k < _sz - 1; k++)
//	{
//		least = k;
//		for (i = k + 1; i < _sz; i++)
//		{
//			if (_data[least] > _data[i])
//			{
//				least = i;
//			}
//
//		}
//
//		temp = _data[least];
//		_data[least] = _data[k];
//		_data[k] = temp;
//
//	}
//}
//
//void doinsertionsort(int _data[], int _sz)
//{
//	int i, j;
//
//	for (i = 1; i < _sz; i++)
//	{
//		int me = _data[i];
//
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (_data[j] > me)
//			{
//				_data[j + 1] = _data[j];
//			}
//			if (_data[j] < me)
//			{
//				break;
//			}
//		}
//		_data[j + 1] = me;
//	}
//}
//
//void doboublesort(int _data[], int _sz)
//{
//	int i, j, temp;
//
//	for (i = 0; i < _sz; i++)
//	{
//		for (j = 0; j < _sz - 1-i; j++)
//		{
//			if (_data[j] > _data[j+1])
//			{
//				temp = _data[j];
//				_data[j] = _data[j+1];
//				_data[j+1] = temp;
//			}
//		}
//	}
//}
//
//void show_data(int _data[], int _sz)
//{
//	for (int i = 0; i < _sz; i++)
//	{
//		printf("%d ", _data[i]);
//	}
//	return;
//}
//
//int main()
//{
//	int data[] = { 45,76,87,20,1 };
//
//	int sz = sizeof(data) / sizeof(data[0]);
//
//	doboublesort(data, sz);
//
//	show_data(data, sz);
//}

#include <stdio.h>

void doselection(int _data[], int _sz)
{
	int i, j, least, temp;
	for (i = 0; i < _sz - 1; i++)
	{
		least = i;
		for (j = i + 1; j < _sz; j++)
		{
			if (_data[least] > _data[j])
			{
				least = j;
			}
		}
		temp = _data[least];
		_data[least] = _data[i];
		_data[i] = temp;
	}
}

void doinsertion(int _data[], int _sz)
{
	int i, j, temp;

	for (i = 1; i < _sz; i++)
	{
		int me = _data[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (me < _data[j])
			{
				_data[j + 1] = _data[j];

			}
			if (me > _data[j])
			{
				break;
			}
		}
		_data[j + 1] = me;
	}
}

void dobouble(int _data[], int _sz)
{
	int i, j, temp;
	for (i = 0; i < _sz; i++)
	{
		for (j = 0; j < _sz - 1 - i; j++)
		{
			if (_data[j] > _data[j + 1])
			{
				temp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = temp;
			}
		}
	}
}

void shell_sort(int _data[], int _sz)
{
	// 1. gap : sz/2 --> 반씩 줄이면서 --> 1이 될때까지
	int gap = 0;
	int i = 0;
	int k = 0;
	for (gap = _sz / 2; gap > 0; gap = gap / 2)
	{
		// insertion sort를 각각의 그룹에 대해서 실행한다.
		for (i = 0; i < gap; i++)
		{
			// 이곳에서 insertion sort를 구현한다.
			for (k = i + gap; k < _sz; k = k + gap)
			{
				int me = _data[k]; // 일단 나보다 큰 애가 있을 수 있으므로 자리를 잠시 비켜준다
				int d = 0;         // 비교할 대상 내 앞에 있는 애들
				for (d = k - gap; d >= 0 && _data[d] > me; d = d - gap)
				{
					_data[d + gap] = _data[d];
				}
				_data[d + gap] = me;
			}
		}

	}
}

int main()
{
	int data[] = { 52,6,32,5,3,47,1 };

	int sz = sizeof(data) / sizeof(data[0]);

	doinsertion(data, sz);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", data[i]);
	}
}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* left;
//	struct node* right;
//};
//
//struct node* root = 0;
//
//void addBST(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->left = nnode->right = 0;
//
//	if (root == 0)
//	{
//		root = nnode;
//		return;
//	}
//	struct node* temp = root;
//	while (1)
//	{
//		if (temp->data < _data)
//		{
//			if (temp->right == 0)
//			{
//				temp->right = nnode;
//				return;
//			}
//			temp = temp->right;
//		}
//		if (temp->data > _data)
//		{
//			if (temp->left == 0)
//			{
//				temp->left = nnode;
//				return;
//			}
//			temp = temp->left;
//		}
//	}
//}
//
//void inorder(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return;
//	}
//	inorder(_r->left);
//	printf("%d ", _r->data);
//	inorder(_r->right);
//}
//
//void delBST(int _data, struct node* _r)
//{
//	if (_r == 0)
//	{
//		return;
//	}
//
//	struct node* temp = root;
//	struct node* temp_p = 0;
//
//	while (1)
//	{
//		if (temp == 0) // 지울 데이터가 없어서 리턴
//		{
//			return;
//		}
//		if (temp->data == _data) // 지울데이터가 있다
//		{
//			if (temp->left == 0 && temp->right == 0)
//			{ 
//				if (temp == _r) 
//				{
//					free(_r);
//					_r = 0;
//					return;
//				}
//				if (temp_p->left == temp)
//				{
//					temp_p->left = 0;
//					free(temp);
//					return;
//				}
//				if (temp_p->right = temp)
//				{
//					temp_p->right = 0;
//					free(temp);
//					return;
//				}
//			}
//
//			if (temp->left != 0 && temp->right == 0) // 왼쪽에 자식을 가지고 있다
//			{
//				if (temp == _r)
//				{
//					_r = _r->left;
//					free(temp);
//					return;
//				}
//				if (temp_p->left == temp)
//				{
//					temp_p->left = temp->left;
//					free(temp);
//					return;
//				}
//				if (temp_p->right = temp)
//				{
//					temp_p->right = temp->left;
//					free(temp);
//					return;
//				}
//			}
//
//			if (temp->left == 0 && temp->right != 0) // 오른쪽에 자식을 가지고 있다
//			{
//				if (temp == _r)
//				{
//					_r = _r->right;
//					free(temp);
//					return;
//				}
//				if (temp_p->left == temp)
//				{
//					temp_p->left = temp->right;
//					free(temp);
//					return;
//				}
//				if (temp_p->right = temp)
//				{
//					temp_p->right = temp->right;
//					free(temp);
//					return;
//				}
//			}
//
//			if (temp->left != 0 && temp->right != 0) // 양쪽에 자시글 가지고있다
//			{
//				struct node* k = temp->right;
//				struct node* k_p = temp;
//				while (k->left != 0)
//				{
//					k_p = k;
//					k = k->left;
//				}
//				 
//				temp->data = k->data; // 중요 데이터를 복사 저장한다
//
//				if (k_p->left == k)
//				{
//					k_p->left = k->right;
//					free(k);
//					return;
//				}
//				if (k_p->right == k)
//				{
//					k_p->right = k->right; 
//					free(k);
//					return;
//				}
//			}
//
//		}
//		else // 내 데이터가 아니면 그거에 맞춰서 왼 오로 이동해준다
//		{
//			if (temp->data < _data)
//			{
//				temp_p = temp;
//				temp = temp->right;
//			}
//			if (temp->data > _data)
//			{
//				temp_p = temp;
//				temp = temp->left;
//			}
//		}
//	}
//}
//
//int main()
//{
//	addBST(100);
//	addBST(50);
//	addBST(200);
//	addBST(10);
//	addBST(70);
//	addBST(150);
//	addBST(250);
//	addBST(5);
//
//	delBST(10,root);
//
//	inorder(root);
//
//}

//#include <stdio.h>
//
//#define HEAP_LEN 10
//int heap[HEAP_LEN];
//int heapsize = 0;
//
//void enqueue(int _data)
//{
//	if (heapsize == (HEAP_LEN - 1))
//	{
//		return;
//	}
//	heapsize++;
//	heap[heapsize] = _data;
//
//	int me = heapsize;
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
//			int temp = heap[me];
//			heap[me] = heap[parent];
//			heap[parent] = temp;
//
//			me = parent;
//			parent = me / 2;
//
//		}
//	}
//}
//
//int findreplacer(int _me)
//{
//	int left = _me * 2;
//	int right = _me * 2 + 1;
//
//	if (heapsize < left)
//	{
//		return 0;
//	}
//	if (heapsize < right)
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
//	if (heapsize == 0)
//	{
//		return -999;
//	}
//	int res = heap[1];
//	heap[1] = heap[heapsize];
//	heapsize--;
//
//	int me = 1;
//	while (1)
//	{
//		int re = findreplacer(me);
//
//		if (re == 0)
//		{
//			return res;
//		}
//
//		if (heap[me] > heap[re])
//		{
//			return res;
//		}
//
//		if (heap[me] < heap[re])
//		{
//			int temp = heap[me];
//			heap[me] = heap[re];
//			heap[re] = temp;
//
//			me = re;
//		}
//	}
//}
//
//int main()
//{
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	enqueue(4);
//	enqueue(5);
//	enqueue(6);
//
//	for (int i = 0; i < 7; i++)
//	{
//		printf("%d ",dequeue());
//	}
//
//}

//#include <stdio.h>
//
//void doselection(int _data[], int _sz)
//{
//	int i, j;
//	for (i = 0; i < _sz - 1; i++)
//	{
//		int least = i;
//		for (j = i + 1; j < _sz; j++)
//		{
//			if (_data[least] > _data[j])
//			{
//				least = j;
//			}
//		}
//		int temp = _data[least];
//		_data[least] = _data[i];
//		_data[i] = temp;
//	}
//}
//
//void doinsertion(int _data[], int _sz)
//{
//	int i, j;
//	for (i = 1; i < _sz; i++)
//	{
//		int me = _data[i];
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (_data[j] > me)
//			{
//				_data[j + 1] = _data[j];
//			}
//			if (_data[j] < me)
//			{
//				break;
//			}
//		}
//		_data[j + 1] = me;
//	}
//
//}
//
//void dobubble(int _data[], int _sz)
//{
//	int i, j;
//	for (i = 0; i < _sz; i++)
//	{
//		for (j = 0; j < _sz - 1 - i; j++)
//		{
//			if (_data[j] > _data[j + 1])
//			{
//				int temp = _data[j];
//				_data[j] = _data[j + 1];
//				_data[j + 1] = temp;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int data[] = { 9,3,5,2,4,7,6,1 };
//	int sz = sizeof(data) / sizeof(data[0]);
//
//	dobubble(data, sz);
//
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ", data[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* left;
//	struct node* right;
//};
//
//struct node* root = 0;
//
//void addBST(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->left = nnode->right = 0;
//
//	if (root == 0)
//	{
//		root = nnode;
//		return;
//	}
//	struct node* temp = root;
//	while (1)
//	{
//		if (temp->data < _data)
//		{
//			if (temp->right == 0)
//			{
//				temp->right = nnode;
//				return;
//			}
//			temp = temp->right;
//		}
//		if (temp->data > _data)
//		{
//			if (temp->left == 0)
//			{
//				temp->left = nnode;
//				return;
//			}
//			temp = temp->left;
//		}
//	}
//}
//
//void delBST(int _data, struct node* _r)
//{
//	if (_r == 0)
//	{
//		return;
//	}
//	
//	struct node* temp = _r;
//	struct node* temp_p = 0;
//
//	while (1)
//	{
//		if (temp->data == _data)
//		{
//			if (temp->left == 0 && temp->right == 0)
//			{
//				if (temp == _r)
//				{
//					free(temp);
//					_r = 0;
//					return;
//				}
//				if (temp_p->left == temp)
//				{
//					temp_p->left = 0;
//					free(temp);
//					return;
//				}
//				if (temp_p->right == temp)
//				{
//					temp_p->right = 0;
//					free(temp);
//					return;
//				}
//			}
//
//			if (temp->left != 0 && temp->right == 0)
//			{
//				if (temp == _r)
//				{
//					_r = _r->left;
//					free(temp);
//					return;
//				}
//				if (temp_p->left == temp)
//				{
//					temp_p->left = temp->left;
//					free(temp);
//					return;
//				}
//				if (temp_p->right == temp)
//				{
//					temp_p->right = temp->left;
//					free(temp);
//					return;
//				}
//			}
//			if (temp->left == 0 && temp->right != 0)
//			{
//				if (temp == _r)
//				{
//					_r = _r->right;
//					free(temp);
//					return;
//				}
//				if (temp_p->left == temp)
//				{
//					temp_p->left = temp->right;
//					free(temp);
//					return;
//				}
//				if (temp_p->right == temp)
//				{
//					temp_p->right = temp->right;
//					free(temp);
//					return;
//				}
//			}
//			if (temp->left != 0 && temp->right != 0)
//			{
//				struct node* k = temp->right;
//				struct node* k_p = temp;
//
//				while(k->left != 0)
//				{
//					k_p = k;
//					k = k->left;
//				}
//
//				temp->data = k->data;
//
//				if (k_p->left == k)
//				{
//					k_p->left = k->right;
//					free(k);
//					return;
//				}
//				if (k_p->right == k)
//				{
//					k_p->right = k->right;
//					free(k);
//					return;
//				}
//
//			}
//		}
//		else
//		{
//			if (temp->data < _data)
//			{
//				temp_p = temp;
//				temp = temp->right;
//			}
//			else
//			{
//				temp_p = temp;
//				temp = temp->left;
//			}
//		}
//	}
//
//
//}
//
//void inorder(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return;
//	}
//	inorder(_r->left);
//	printf("%d ", _r->data);
//	inorder(_r->right);
//}
//
//int main()
//{
//	addBST(100);
//	addBST(50);
//	addBST(200);
//	addBST(10);
//	addBST(70);
//	addBST(150);
//	addBST(250);
//	addBST(5);
//
//	delBST(5,root);
//
//	inorder(root);
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		else if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[j] > nums[i])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//
//
//	}
//	for (i = start; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//
//
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//	
//	merge_sort(nums, start, (start + end) / 2, tarray);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//}
//
//int main()
//{
//	int nums[] = { 23,32,12,56,78,60,2,9,4,14,100,1,23 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	merge_sort(nums, 0, sz - 1, tarray);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void quick_sort(int nums[], int start, int end)
//{
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end)
//	{
//		return;
//	}
//	while (low <= high)
//	{
//		while (nums[low] <= nums[pivot] && low <= end)
//		{
//			low++;
//		}
//		while (nums[high] >= nums[pivot] && high >= start+1)
//		{
//			high--;
//		}
//		if (low < high)
//		{
//			int temp = nums[low];
//			nums[low] = nums[high];
//			nums[high] = temp;
//		}
//
//	}
//
//	int temp = nums[high];
//	nums[high] = nums[pivot];
//	nums[pivot] = temp;
//
//	quick_sort(nums, start, high - 1);
//	quick_sort(nums, high + 1, end);
//
//}
//
//int main()
//{
//	int nums[] = { 23,32,34,100,87,76,23,65,2,90,21,1,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	quick_sort(nums, 0, sz - 1);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void do_merge(int nums[], int tarray[], int start,int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if ((i > lend) && (j > rend))
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] > nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[i] < nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//}
//
//int main() 
//{
//	int nums[] = { 12,2,3,65,98,26,48,51,20,7,1,100,77 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	merge_sort(nums, 0, sz - 1, tarray);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//
//void quick_sort(int nums[], int start, int end)
//{
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end)
//	{
//		return;
//	}
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
//
//
//	}
//
//	int temp = nums[pivot];
//	nums[pivot] = nums[high];
//	nums[high] = temp;
//
//	quick_sort(nums, start, high - 1);
//	quick_sort(nums, high + 1, end);
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
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break; // 이거 브레이크임 return 아님 주의
//		}
//		if (lend < i)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (rend < j)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//	}
//
//	for (i = start ; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//	merge_sort(nums, start, (start + end) / 2, tarray);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//}
//
//int main()
//{
//	int nums[] = { 23,12,56,89,100,10,23,75,2,6,16 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	merge_sort(nums, 0, sz - 1, tarray);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//
//void quick_sort(int nums[], int start, int end)
//{
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end)
//	{
//		return;
//	}
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
//		
//	}
//	int temp = nums[high];
//	nums[high] = nums[pivot];
//	nums[pivot] = temp;
//
//	quick_sort(nums, start, high - 1);
//	quick_sort(nums, high+1, end);
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
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//}
//
//int main()
//{
//	int nums[] = { 23,12,56,89,100,10,23,75,2,6,16 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	merge_sort(nums, 0, sz - 1, tarray);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//
//void quick_sort(int nums[], int start, int end)
//{
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end)
//	{
//		return;
//	}
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
//
//	}
//	int temp = nums[high];
//	nums[high] = nums[pivot];
//	nums[pivot] = temp;
//
//	quick_sort(nums, start, high - 1);
//	quick_sort(nums, high + 1, end);
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
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[j] < nums[i])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//}
//
//int main()
//{
//	int nums[] = { 12,23,65,1,98,100,32,13,79,65,5 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	merge_sort(nums, 0, sz - 1, tarray);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

//#include <stdio.h>
//
//void quick_sort(int nums[], int start, int end)
//{
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end)
//	{
//		return;
//	}
//	while (low <= high)
//	{
//		while (nums[low] <= nums[pivot] && low <= end)
//		{
//			low++;
//		}
//		while (nums[high] > nums[pivot] && high >= start + 1)
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
//	int temp = nums[pivot];
//	nums[pivot] = nums[high];
//	nums[high] = temp;
//
//	quick_sort(nums, start, high - 1);
//	quick_sort(nums, high + 1, end);
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
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//
////int cnt = 0;
//
//int do_merge(int nums[], int tarray[], int start, int mid, int end,int num)
//{
//	int cnt_buf = 0;
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		if (tarray[i]==num&&nums[i]!=tarray[i]) // 자리가 바뀜을 표시
//		{
//			cnt_buf++;
//		}
//		nums[i] = tarray[i];
//	}
//	return cnt_buf;
//
//}
//
//int merge_sort(int nums[], int start, int end, int tarray[],int num)
//{
//	static int cnt = 0;
//	if (start == end)
//	{
//		return 0;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray,num);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray,num);
//
//	cnt+=do_merge(nums, tarray, start, (start + end) / 2, end,num);
//
//	return cnt;
//}
//
//int main()
//{
//	int nums[] = { 12,56,1,3,9,32,26 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	int num = 12;
//
//	int res=merge_sort(nums, 0, sz - 1, tarray,num);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n%d\n", res);
//}

//#include <stdio.h>
//int num_siz = 0;
//int pivot_signal = 0;
//void show_neighbor(int nums[], int index)
//{
//	if (index - 1 >= 0)
//	{
//		printf("%d ", nums[index - 1]);
//	}
//	else
//	{
//		printf("-999 ");
//	}
//
//	if (index + 1 < num_siz)
//	{
//		printf("%d ", nums[index + 1]);
//	}
//	else
//	{
//		printf("-999 ");
//	}
//
//
//}
//
//void quick_sort(int nums[], int start, int end,int num)
//{
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	if (start >= end)
//	{
//		return;
//	}
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
//	int temp = nums[pivot];
//	nums[pivot] = nums[high];
//	nums[high] = temp;
//
//	printf("\npivot : %3d\n", nums[high]);
//	for (int i = 0; i <= 9; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n");
//
//	if (nums[high]==num)
//	{
//		pivot_signal++;
//		show_neighbor(nums, high);
//	}
//
//	quick_sort(nums, start, high - 1,num);
//	quick_sort(nums, high + 1, end,num);
//
//}
//
//int main()
//{
//	int nums[] = { 15,68,35,95,100,1,3,58,15,7 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	num_siz = sz;
//
//	int num = 999;
//
//	quick_sort(nums, 0, sz - 1,num);
//
//	printf("\n----------------------------\n");
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//
//	if (!pivot_signal)
//	{
//		printf("\n-999\n");
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cnt = 0;
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end, int num)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		if (tarray[i] == num && tarray[i] != nums[i]) // tarray[i] nums[i] 두 값이 달라야 됨 주의
//		{
//			cnt++;
//		}
//		nums[i] = tarray[i];
//	}
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[], int num)
//{
//	if (start == end)
//	{
//		return;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray, num);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray, num);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end, num);
//
//}
//
//int main()
//{
//	int nums[] = { 2,6,7,4,1,8,5,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	int num = 2;
//
//	merge_sort(nums, 0, sz - 1, tarray, num);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n%d\n", cnt);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int do_merge(int nums[], int tarray[], int start, int mid, int end, int num)
//{
//	int cnt_buf = 0;
//
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		if (tarray[i] == num && tarray[i] != nums[i])
//		{
//			cnt_buf++;
//		}
//		nums[i] = tarray[i];
//	}
//
//	return cnt_buf;
//}
//
//int merge_sort(int nums[], int start, int end, int tarray[], int num)
//{
//	static int cnt = 0;
//
//	if (start == end)
//	{
//		return 0;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray, num);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray, num);
//
//	cnt += do_merge(nums, tarray, start, (start + end) / 2, end, num);
//	return cnt;
//}
//
//int main()
//{
//	int nums[] = { 2,6,7,4,1,8,5,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	int num = 4;
//
//	int res = merge_sort(nums, 0, sz - 1, tarray, num);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n%d 가 움직인 횟수 : %d\n", num, res);
//
//}

//#include <stdio.h>
//
//void show(int nums[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//	printf("\n");
//}
//
//void show_naver(int nums[], int idx,int sz)
//{
//	if ((idx - 1) >=0)
//	{
//		printf("%d ", nums[idx - 1]);
//	}
//	else
//	{
//		printf("-999 ");
//	}
//
//	if ((idx + 1) < sz)
//	{
//		printf("%d ", nums[idx + 1]);
//	}
//	else
//	{
//		printf("-999 ");
//	}
//
//	printf("\n");
//}
//
//int cnt_check = 0;
//
//void quick_sort(int nums[], int start, int end,int num)
//{
//	
//
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//	
//	if (start >= end)
//	{
//		return;
//	}
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
//
//		if (low < high)
//		{
//			int temp = nums[low];
//			nums[low] = nums[high];
//			nums[high] = temp;
//		}
//	}
//	int temp = nums[high];
//	nums[high] = nums[pivot];
//	nums[pivot] = temp;
//
//	show(nums, 10);
//
//	if (nums[high] == num)
//	{
//		cnt_check++;
//		show_naver(nums, high, 10);
//	}
//
//
//
//	quick_sort(nums, start, high - 1,num);
//	quick_sort(nums, high + 1,end,num);
//
//
//}
//
//int main()
//{
//	int nums[] = { 15,68,35,95,100,15,1,3,58,7 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//
//
//	int num = 100;
//
//	quick_sort(nums, 0, sz - 1,num);
//
//	show(nums, sz);
//
//	if (!cnt_check)
//	{
//		printf("\n-999\n");
//	}
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int do_merge(int nums[], int tarray[], int start, int mid, int end, int num)
//{
//	int buf = 0;
//
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart;
//	int j = rstart;
//	int t = lstart;
//
//	while (1)
//	{
//		if (i > lend && j > rend)
//		{
//			break;
//		}
//		if (i > lend)
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] <= nums[j])
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (nums[i] >= nums[j])
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//	}
//
//	for (i = start; i <= end; i++)
//	{
//		if (tarray[i] == num && tarray[i] != nums[i])
//		{
//			buf++;
//		}
//		nums[i] = tarray[i];
//	}
//	return buf;
//}
//
//int merge_sort(int nums[], int start, int end, int tarray[], int num)
//{
//	static int cnt = 0;
//	if (start == end)
//	{
//		return 0;
//	}
//
//	merge_sort(nums, start, (start + end) / 2, tarray, num);
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray, num);
//
//	cnt += do_merge(nums, tarray, start, (start + end) / 2, end, num);
//}
//
//
//int main()
//{
//	int nums[] = { 2,6,7,4,1,8,5,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	int num = 4;
//
//	int res = merge_sort(nums, 0, sz - 1, tarray, num);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//
//	if (res)
//		printf("\n%d \n", res);
//
//	else if (!res)
//		printf("\n999 \n");
//
//
//}

//#include <stdio.h>
//
//int quick_sort(int nums[], int start, int end ,int num)
//{
//	if (start >= end)   // 예외처리 무조건 해줘야됨
//	{
//		return 0;
//	}
//	static int buf = 0;
//	int pivot = start;
//	int low = start + 1;
//	int high = end;
//
//	while (low <= high)
//	{
//		if (nums[low] <= nums[pivot] && low <= end)
//		{
//			low++;
//		}
//		if (nums[high] >= nums[pivot] && high >= start + 1)
//		{
//			high--;
//		}
//		if (low < high)
//		{
//			int temp = nums[high];
//			nums[high] = nums[low];
//			nums[low] = temp;
//		}
//
//	}
//	int temp = nums[pivot];
//	nums[pivot] = nums[high];
//	nums[high] = temp;
//
//	if (nums[high] == num)
//	{
//		buf++;
//		if (high - 1 >= 0)
//			printf("%d ", nums[high-1]);
//		else
//			printf("-999 ");
//		if (high + 1 <= end)
//			printf("%d \n", nums[high+1]);
//		else
//			printf("-999\n");
//	}
//	
//
//	quick_sort(nums, start, high - 1,num);
//	quick_sort(nums, high + 1, end,num);
//
//	return buf;
//}
//
//int main()
//{
//	int nums[] = { 23,32,34,100,87,76,23,65,2,90,21,1,3 };
//
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	int num = 999;
//
//	printf("%d가 피봇일때 양쪽 수는? \n", num);
//
//	int res=quick_sort(nums, 0, sz - 1,num);
//
//	if (!res)
//	{
//		printf("-999");
//	}
//
//}
