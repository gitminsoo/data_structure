// recursion 하노이

//#include <stdio.h>
//
//void hanoi(int num,int start,int temp,int end)
//{
//	if (num == 1)
//	{
//		printf("%d를 %d로 옮기시오\n", start, end);
//		return;
//	}
//	hanoi(num - 1, start, end, temp);
//	hanoi(1, start, temp, end);
//	hanoi(num - 1, temp, start, end);
//
//}
//
//int main()
//{
//	hanoi(3, 1, 2, 3);
//}

// sll

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//};
//
//struct node* head = 0;
//
//void addLidst(int v)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//		return;
//	}
//	struct node* temp = head;
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//	temp->next = nnode;
//}
//
//void show()
//{
//	struct node* temp = head;
//	while (temp != 0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	return;
//}
//
//void insert_back(int a, int v)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//
//	struct node* temp = head;
//
//	while (temp != 0)
//	{
//		if (temp->data == a)
//		{
//			if (temp->next == 0)
//			{
//				temp->next = nnode;
//				return;
//			}
//			else
//			{
//				nnode->next = temp->next;
//				temp->next = nnode;
//				return;
//			}
//		}
//		temp = temp->next;
//	}
//}
//
//void insert_front(int a, int v)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//
//	struct node* temp = head;
//	struct node* temp_p = 0;
//
//	while (temp != 0)
//	{
//		if (temp->data == a)
//		{
//			if (temp == head)
//			{
//				nnode->next = head;
//				head = nnode;
//				return;
//			}
//			else
//			{
//				temp_p->next = nnode;
//				nnode->next = temp;
//				return;
//			}
//		}
//		temp_p = temp;
//		temp = temp->next;
//	}
//}
//
//void delList(int v)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* temp = head;
//	struct node* temp_p = 0;
//
//	while (temp != 0) {
//		if (temp->data == v)
//		{
//			if (temp == head)
//			{
//				if (temp->next == 0)
//				{
//					free(temp);
//					head = 0;
//					return;
//				}
//				else
//				{
//					head = head->next;
//					free(temp);
//					temp = head;
//					continue;
//				}
//			}
//			else
//			{
//				if (temp->next == 0)
//				{
//					temp_p->next = 0;
//					free(temp);
//					temp = temp_p;
//					continue;
//				}
//				else
//				{
//					temp_p->next = temp->next;
//					free(temp);
//					temp = temp_p;
//					continue;
//
//				}
//			}
//		}
//
//		temp_p = temp;
//		temp = temp->next;
//	}
//
//}
//
//int main()
//{
//	addLidst(1);
//	addLidst(2);
//	addLidst(3);
//	addLidst(4);
//	addLidst(5);
//
//	insert_front(1, 3);
//	delList(3);
//
//	insert_back(2, 2);
//	delList(2);
//
//	show();
//
//}

// dll

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//	struct node* prev;
//};
//
//struct node* head = 0;
//
//void addList(int v)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->next = nnode->prev = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//		return;
//	}
//
//	struct node* temp = head;
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//	temp->next = nnode;
//	nnode->prev = temp;
//}
//
//void show()
//{
//	struct node* temp = head;
//	while (temp != 0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//}
//
//void insert_front(int a, int v)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->next = nnode->prev = 0;
//
//	struct node* temp = head;
//
//	while (temp != 0)
//	{
//		if (temp->data == a)
//		{
//			if (temp == head)
//			{
//				nnode->next = temp;
//				temp->prev = nnode;
//				head = nnode;
//				return;
//			}
//			else
//			{
//				nnode->next = temp;
//				nnode->prev = temp->prev;
//				nnode->prev->next = nnode;
//				temp->prev = nnode;
//				return;
//			}
//		}
//		temp = temp->next;
//	}
//}
//
//void insert_rear(int a, int v)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->next = nnode->prev = 0;
//
//	struct node* temp = head;
//
//	while (temp != 0)
//	{
//		if (temp->data == a)
//		{
//			if (temp -> next ==0)
//			{
//				nnode->prev = temp;
//				temp->next = nnode;
//				return;
//			}
//			else
//			{
//				nnode->next = temp->next;
//				nnode->prev = temp;
//				nnode->next->prev = nnode;
//				temp->next = nnode;
//				return;
//			}
//		}
//		temp = temp->next;
//	}
//}
//
//void delList(int v)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* temp = head;
//	while (temp != 0)
//	{
//		if (temp->data == v)
//		{
//			if (temp == head)
//			{
//				if (temp->next == 0)
//				{
//					free(temp);
//					head = 0;
//					return;
//				}
//				else
//				{
//					head = head->next;
//					head->prev = 0;
//					free(temp);
//					temp = head;
//					continue;
//				}
//			}
//			else
//			{
//				if (temp->next == 0)
//				{
//					temp->prev->next = 0;
//					free(temp);
//					return;
//				}
//				else
//				{
//					struct node* t = temp->prev;
//					temp->prev->next = temp->next;
//					temp->next->prev = temp->prev;
//					free(temp);
//					temp = t;
//					
//				}
//			}
//		}
//		temp = temp->next;
//	}
//}
//
//int main()
//{
//	addList(1);
//	addList(2);
//	addList(3);
//	addList(4);
//	addList(5);
//
//	insert_front(1, 1);
//	insert_rear(5, 5);
//	delList(1);
//	delList(5);
//
//	show();
//}

// BST

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
//void addBST(int v)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = v;
//	nnode->left = nnode->right = 0;
//
//	if (root == 0)
//	{
//		root = nnode;
//		return;
//	}
//	struct node* temp = root;
//
//	while (1)
//	{
//		if (temp->data > v)
//		{
//			if (temp->left == 0)
//			{
//				temp->left = nnode;
//				return;
//			}
//			temp = temp->left;
//		}
//		else
//		{
//			if (temp->right == 0)
//			{
//				temp->right = nnode;
//				return;
//			}
//			temp = temp->right;
//		}
//	}
//}
//
//void inorder(struct node* r)
//{
//	if (r == 0)
//	{
//		return;
//	}
//	inorder(r->left);
//	printf("%d ", r->data);
//	inorder(r->right);
//}
//
//void delBST(int v)
//{
//	if (root == 0)
//	{
//		return;
//	}
//	struct node* temp = root;
//	struct node* temp_p = 0;
//
//	while (1)
//	{
//		if (temp == 0)
//		{
//			return;
//		}
//		if (temp->data == v)
//		{
//			if (temp->left == 0 && temp->right == 0)
//			{
//				if (temp == root)
//				{
//					free(temp);
//					root = 0;
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
//				if (temp == root)
//				{
//					root = root->left;
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
//				if (temp == root)
//				{
//					root = root->right;
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
//			else if (temp->left != 0 && temp->right != 0)
//			{
//				struct node* k = temp->right;
//				struct node* k_p = temp;
//
//				while (k->left != 0)
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
//				else
//				{
//					k_p->right = k->right;
//					free(k);
//					return;
//				}
//			}
//
//		}
//		else
//		{
//			temp_p = temp;
//			if (temp->data > v)
//			{
//				temp = temp->left;
//			}
//			else
//			{
//				if (temp->data < v)
//				{
//					temp = temp->right;
//				}
//			}
//		}
//	}
//	
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
//	addBST(90);
//
//	delBST(100);
//
//	inorder(root);
//
//}

// max_heap

//#include <stdio.h>
//#include <stdlib.h>
//
//#define HL 10
//
//int heapsize = 0;
//int heap[HL];
//
//void enqueue(int v)
//{
//	if (heapsize == HL - 1)
//	{
//		return;
//	}
//	heapsize++;
//	heap[heapsize] = v;
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
//		if (heap[parent] > heap[me])
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
//		}
//	}
//
//}
//
//int find_re(int me)
//{
//	int left = me * 2;
//	int right = left + 1;
//
//	if (heapsize < left)
//	{
//		return 0;
//	}
//	else if (heapsize < right)
//	{
//		return left;
//	}
//	else if (heap[left] > heap[right])
//	{
//		return left;
//	}
//	else if (heap[left] < heap[right])
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
//
//	int res = heap[1];
//	heap[1] = heap[heapsize];
//	heapsize--;
//
//	int me = 1;
//	while(1)
//	{
//		int re = find_re(me);
//		if (re == 0)
//		{
//			return res;
//		}
//		if (heap[me] > heap[re])
//		{
//			return res;
//		}
//		else
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
//	enqueue(7);
//	enqueue(3);
//	enqueue(9);
//	enqueue(2);
//	enqueue(8);
//	enqueue(10);
//	enqueue(4);
//
//	for (int i = 0; i < 8; i++)
//	{
//		printf("%d ",dequeue());
//	}
//
//}

// 정렬 

//#include <stdio.h>
//#include <stdlib.h>
//
//void selection(int nums[], int sz)
//{
//
//	for (int i = 0; i < sz - 1; i++)
//	{
//		int least = i;
//		for (int j = i + 1; j < sz; j++)
//		{
//			if (nums[least] >= nums[j])
//			{
//				
//				least = j;
//			}
//		}
//		int temp = nums[least];
//		nums[least] = nums[i];
//		nums[i] = temp;
//	}
//
//}
//
//void insertion(int nums[], int sz)
//{
//	int i, j;
//
//	for (i = 1; i < sz; i++)
//	{
//		int me = nums[i];
//		for (j = i - 1; j >= 0 && me < nums[j]; j--)
//		{
//			nums[j + 1] = nums[j];
//		}
//		nums[j + 1] = me;
//	}
//}
//
//void bubble(int nums[], int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		for (int j = 0; j < sz - 1 - i; j++)
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
//void shell(int nums[], int sz)
//{
//	int gap = 0;
//	int i, j, d;
//
//	for (gap = sz / 2; gap > 0; gap = gap / 2)
//	{
//		for (i = 0; i < gap; i++)
//		{
//			for (j = i + gap; j < sz; j = j + gap)
//			{
//				int me = nums[j];
//				for (d = j - gap; d >= 0 && nums[d] > me; d = d - gap) // 여기 잘 보기
//				{
//					nums[d + gap] = nums[d];
//				}
//				nums[d + gap] = me;
//			}
//		}
//	}
//}
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
//			t++; j++;
//		}
//		else if (j > rend)
//		{
//			tarray[t] = nums[i];
//			t++; i++;
//		}
//		else if (nums[i] > nums[j])
//		{
//			tarray[t] = nums[j];
//			t++; j++;
//		}
//		else if (nums[j] > nums[i])
//		{
//			tarray[t] = nums[i];
//			t++; i++;
//		}
//
//	}
//
//	for (int i = start; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//}
//
//void merge(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//	
//	merge(nums, start, (start + end) / 2, tarray);
//	merge(nums, (start + end)/2 + 1, end, tarray);
//
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//}
//
//void quick(int nums[], int start, int end)
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
//		while (nums[low] < nums[pivot] && low <= end)
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
//
//	int temp = nums[pivot];
//	nums[pivot] = nums[high];
//	nums[high] = temp;
//
//	quick(nums, start, high - 1);
//	quick(nums, high + 1, end);
//}
//
//int main()
//{
//	int nums[10] = { 7,2,3,9,1,10,6,4,8,5 };
//
//	int sz = sizeof(nums) / sizeof(nums[0]);
//	int* tarray = (int*)malloc(sizeof(int)*sz);
//
//	//shell(nums, sz);
//
//	//merge(nums, 0, sz - 1, tarray);
//
//	quick(nums, 0, sz - 1);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d ", nums[i]);
//	}
//}

// dfs bfs

//#include <stdio.h>
//
//#define NV 5
//
//int visited[NV];
//
//int stack[NV];
//int top = -1;
//
//int queue[NV];
//int front = 0;
//int rear = 0;
//
//void addEdge(int graph[][NV], int v1, int v2)
//{
//	graph[v1][v2] = 1;
//	graph[v2][v1] = 1;
//}
//
//void push(int v)
//{
//	if (top == NV - 1)
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
//	for (int i = 0; i <= top; i++)
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
//	if (front == (rear + 1) % NV)
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
//void pAV(int graph[][NV], int v, int(*check)(int), void(*add)(int))
//{
//	for (int i = 0; i < NV; i++)
//	{
//		if (graph[i][v] && visited[i] == 0 && (*check)(i) == 0)
//		{
//			(*add)(i);
//		}
//	}
//}
//
//void DFS(int graph[][NV], int start)
//{
//	push(start);
//	while (1)
//	{
//		int v = pop();
//		if (v == -999)
//		{
//			return;
//		}
//		printf("%d ",v);
//		visited[v] = 1;
//		pAV(graph, v, &instack, &push);
//	}
//}
//
//void BFS(int graph[][NV], int start)
//{
//	enqueue(start);
//	while (1)
//	{
//		int v = dequeue();
//		if (v == -999)
//		{
//			return;
//		}
//		printf("%d ", v);
//		visited[v] = 1;
//		pAV(graph, v, &inqueue, &enqueue);
//	}
//}
//
//int main()
//{
//	int graph[NV][NV] = { 0 };
//	addEdge(graph, 0, 1);
//	addEdge(graph, 0, 2);
//	addEdge(graph, 2, 1);
//	addEdge(graph, 2, 3);
//	addEdge(graph, 3, 1);
//	addEdge(graph, 3, 4);
//
//	BFS(graph, 0);
//}

// mst

//#include <stdio.h>
//
//#define NV 5
//
//void addEdge(int graph[][NV], int v1, int v2, int w)
//{
//	graph[v1][v2] = w;
//	graph[v2][v1] = w;
//}
//
//void prim(int graph[][NV], int start)
//{
//	int visited[NV] = { 0 };
//	visited[start] = 1;
//
//	for (int cnt = 0; cnt < NV - 1; cnt++)
//	{
//		int mindist = 9999;
//		int visit = -1;
//		int non_visit = -1;
//
//		for (int i = 0; i < NV; i++)
//		{
//			if (visited[i] == 1)
//			{
//				for (int j = 0; j < NV; j++)
//				{
//					if (visited[j] == 0)
//					{
//						if (graph[i][j] && graph[i][j] < mindist)
//						{
//							mindist = graph[i][j];
//							visit = i;
//							non_visit = j;
//						}
//					}
//				}
//			}
//		}
//
//		printf("%d %d\n", visit, non_visit);
//		visited[non_visit] = 1;
//
//	}
//}
//
//void kruskal(int graph[][NV])
//{
//	int family[NV] = { 0,1,2,3,4 };
//	for (int cnt = 0; cnt < NV - 1; cnt++)
//	{
//		int mindist = 9999;
//		int v1 = -1;
//		int v2 = -1;
//
//		for (int i = 0; i < NV; i++)
//		{
//			for (int j = i + 1; j < NV; j++)
//			{
//				if (family[i] != family[j])
//				{
//					if (graph[i][j] && graph[i][j] < mindist)
//					{
//						mindist = graph[i][j];
//						v1 = i;
//						v2 = j;
//					}
//				}
//			}
//		}
//
//		printf("%d %d\n", v1, v2);
//
//		int new_fam = family[v1];
//		int old_fam = family[v2];
//
//		for (int k = 0; k < NV; k++)
//		{
//			if (family[k] == old_fam)
//			{
//				family[k] = new_fam;
//			}
//		}
//
//	}
//}
//
//int main()
//{
//	int graph[NV][NV] = { 0 };
//
//	addEdge(graph, 0, 1, 100);  // 0-->1 edge, weight=100
//	addEdge(graph, 0, 2, 10);
//	addEdge(graph, 1, 2, 40);
//	addEdge(graph, 1, 3, 50);
//	addEdge(graph, 2, 3, 1);
//	addEdge(graph, 3, 4, 10);
//
//
//	// MST by prim
//	// start ver = 0 ,prim으로 찾는다
//	//prim(graph,0);
//
//	// MST by kruskal
//	kruskal(graph);
//
//}

// 다익

//#include <stdio.h>
//
//#define G_SZ 7
//
//void addedge(int graph[][G_SZ], int v1, int v2, int w)
//{
//	graph[v1][v2] = w;
//	graph[v2][v1] = w;
//
//}
//
//struct dijk {
//	int prev;
//	int dist;
//	int done;
//};
//
//void inittable(dijk dtable[])
//{
//	for (int i = 0; i < G_SZ; i++)
//	{
//		dtable[i].dist = 999;
//		dtable[i].done = 0;
//		dtable[i].prev = -1;
//	}
//}
//
//int find_short(dijk dtable[])
//{
//	int idx = -1;
//	int mindist = 9999;
//
//	for (int i = 0; i < G_SZ; i++)
//	{
//		if (dtable[i].done == 0 && dtable[i].dist < mindist)
//		{
//			idx = i;
//			mindist = dtable[i].dist;
//		}
//	}
//	return idx;
//}
//
//void show_dtable(dijk dtable[])
//{
//	for (int i = 1; i < G_SZ; i++)
//	{
//		printf("%5d", i);
//	}
//	printf("\n");
//
//	for (int i = 1; i < G_SZ; i++)
//	{
//		printf("%5d", dtable[i].prev);
//	}
//	printf(" --- prev\n");
//
//	for (int i = 1; i < G_SZ; i++)
//	{
//		printf("%5d", dtable[i].dist);
//	}
//	printf(" --- dist\n");
//
//	for (int i = 1; i < G_SZ; i++)
//	{
//		printf("%5d", dtable[i].done);
//	}
//	printf(" --- done\n");
//}
//
//void show_path(int s, int e, dijk dtable[])
//{
//	int cur = e;
//	while (cur != s)
//	{
//		printf("%d ", cur);
//		cur = dtable[cur].prev;
//	}
//	printf("%d\n",s);
//}
//
//int main()
//{
//
//
//	int graph[7][7] = {
//		//0  1  2  3  4  5  6
//		{-1,-1,-1,-1,-1,-1,-1}, // 0
//		{-1,-1, 3,-1,15,-1,-1}, // 1
//		{-1, 3,-1,30, 2,-1,-1}, // 2
//		{-1,-1,30,-1,-1, 3, 4}, // 3
//		{-1,15, 2,-1,-1, 1,-1}, // 4
//		{-1,-1,-1, 3, 1,-1,20}, // 5
//		{-1,-1,-1, 4,-1,20,-1}  // 6
//
//	};
//	
//	dijk dtable[G_SZ];
//
//	inittable(dtable);
//
//	int start = 1;
//
//	dtable[start].done = 1;
//
//	for (int i = 0; i < G_SZ; i++)
//	{
//		if (graph[i][start] != -1)
//		{
//			dtable[i].prev = start;
//			dtable[i].dist = graph[start][i];
//		}
//	}
//
//	while (1)
//	{
//		int v = find_short(dtable);
//		if (v == -1)
//		{
//			break;
//		}
//
//		dtable[v].done = 1;
//
//		for (int i = 0; i < G_SZ; i++)
//		{
//			if (graph[v][i]>-1 && dtable[i].done == 0)
//			{
//				if (dtable[i].dist > dtable[v].dist + graph[v][i])
//				{
//					dtable[i].dist = dtable[v].dist + graph[v][i];
//					dtable[i].prev= v;
//				}
//			}
//		}
//	}
//	show_dtable(dtable);
//	printf("\n\n");
//	show_path(1, 6, dtable);
//	return 0;
//
//}

// topological



// ford

// hashing