//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning (disable:4996)
//
//#define NV 5
//
//int visited[NV];
//
//int queue[NV];
//int rear = 0;
//int front = 0;
//
//struct node {
//	int data;
//	struct node* next;
//};
//
//struct node* head = 0;
//
//void addedge(int graph[][NV], int v1, int v2)
//{
//	graph[v1][v2] = 1;
//	graph[v2][v1] = 1;
//}
//
//void addnode(int v)
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
//	if (rear == front)
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
//void process(int graph[][NV], int v, int(*check)(int), void(*add)(int))
//{
//	int i;
//	for (i = 0; i < NV; i++)
//	{
//		if (graph[v][i] == 1)
//		{
//			if (visited[i] == 0 && (*check)(i) == 0)
//			{
//				(*add)(i);
//			}
//		}
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
//		//printf("%d 방문\n", v);
//		addnode(v);
//		visited[v] = 1;
//		process(graph, v, &inqueue, &enqueue);
//	}
//}
//
//int find(int v1, int v2)
//{
//	int check1 = 0;
//	int check2 = 0;
//	int cnt = 0;
//	struct node* temp = head;
//	if (temp == 0)
//	{
//		return -999;
//	}
//	while (temp != 0)
//	{
//		if (temp->data == v1)
//		{
//			check1 = cnt;
//		}
//		if (temp->data == v2)
//		{
//			check2 = cnt;
//		}
//		cnt++;
//		temp = temp->next;
//	}
//	if (check1 > check2)
//	{
//		return 0;
//	}
//	if (check1 < check2)
//	{
//		return 1;
//	}
//	if (check1 == check2)
//	{
//		return -999;
//	}
//
//}
//void show()
//{
//	struct node* temp = head;
//	if (head == 0)
//	{
//		return;
//	}
//	while (temp != 0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//}
//
//int main()
//{
//	int graph[NV][NV] = { 0 };
//
//	int n;
//	scanf("%d", &n);
//	for (int i = 0; i < n; i++)
//	{
//		int v1, v2;
//		scanf("%d %d", &v1, &v2);
//
//		if (v1 == -1 && v2 == -1)
//		{
//			break;
//		}
//
//		addedge(graph, v1, v2);
//	}
//	BFS(graph, 0);
//	//show();
//
//	int c1 = 0;
//	int c2 = 0;
//	scanf("%d %d", &c1, &c2);
//
//	printf("%d", find(c1, c2));
//
//
//	/*addedge(graph,0, 1);
//	addedge(graph,0, 2);
//
//	find(0, 1);*/
//
//
//}

// 온라인 저지 시험 본거 복습
//  #pragma warning(disable:4996)

// recursion 1554,1555

//#include <stdio.h>
//
//#pragma warning(disable:4996)
//
//int sum_re(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//
//	return sum_re(n - 1) + n;
//
//}
//
//int main() {
//	int n = 0;
//	scanf("%d", &n);
//
//	int sum = sum_re(n);
//
//	printf("%d", sum);
//}

//#include <stdio.h>
//#pragma warning(disable:4996)
//int multi_re(int a,int b)
//{
//	if (a == 1)
//	{
//		return 1;
//	}
//	return a * (b - 1) + a;
//}
//
//int main()
//{
//	int a, b;
//	scanf("%d %d", &a, &b);
//
//	int mul=multi_re(a, b);
//
//	printf("%d\n", mul);
//}

// 구조체 1556

////#include <stdio.h>
////
/////*
////구조체 struct A를 선언하시오
//// --- 이 부분을 완성하시오
////
////*/
////
////struct A {
////	int age;
////	int weight;
////};
////
//////------아래 부분은 절대 손대지 마세요 ------------------
////
////int main(void) {
////
////	struct A k;
////	int a, b;
////	scanf("%d %d", &a, &b);
////
////	k.age = a;
////	k.weight = b;
////
////	printf("%d", k.age + k.weight);
////	return 0;
////}

// 배열인수 1557

////#include <stdio.h>
////
/////*
////함수 foo를 작성하시오.
////foo는 길이 3인 array를 인수로 받아,
////각 요소의 값 중 짝수는 2로 나눈 "나머지"로 바꾸는 역할을 한다.
////*/
////
////void foo(int num[])
////{
////	for (int i = 0; i < 3; i++)
////	{
////		if (num[i] % 2 == 0)
////		{
////			num[i] = num[i] % 2;
////		}
////	}
////}
////
//////------아래 부분은 절대 손대지 마세요 ------------------
////
////int main(void) {
////
////	int memo[3];
////	int a;
////	int i;
////	for (i = 0; i < 3; i++) {
////		scanf("%d", &a);
////		memo[i] = a;
////	}
////
////	foo(memo);
////	printf("%d %d %d", memo[0], memo[1], memo[2]);
////	return 0;
////}

// sll 1558

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//};
//struct node* head = 0;
//
//void addToSLL(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
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
//int main(void) {
//
//	int d;
//	int i;
//	struct node* k = 0;
//
//	while (1) {
//		scanf("%d", &d);
//		if (d < 0) {
//			break;
//		}
//		addToSLL(d);
//	}
//
//	k = head;
//	for (i = 0; i < -d; i++) {
//		k = k->next;
//	}
//	printf("%d", k->data);
//	return 0;
//}

// dll 1559

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//	struct node* prev;
//};
//struct node* head = 0;
//
//void addToDLL(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = nnode->prev = 0;
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
//	nnode -> prev = temp;
//}
//
//int main(void) {
//
//	int d;
//	int i;
//	struct node* k = 0;
//
//	while (1) {
//		scanf("%d", &d);
//		if (d < 0) {
//			break;
//		}
//		addToDLL(d);
//	}
//
//	k = head;
//	for (i = 0; i < -d; i++) {
//		k = k->next;
//	}
//	k = k->prev;
//	printf("%d", k->data);
//	return 0;
//}

// stack 1560

//#include <stdio.h>
//
//#define STK_SIZE 10
//int my_stack[STK_SIZE];
//int top = -1;
//
//void push(int v)
//{
//	if (top == (STK_SIZE - 1))
//	{
//		return;
//	}
//	top++;
//	my_stack[top] = v;
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		return -999;
//	}
//	int res = my_stack[top];
//	top--;
//	return res;
//}
//
//int main(void) {
//
//	int d;
//
//	while (1) {
//		scanf("%d", &d);
//		if (d < 0) {
//			break;
//		}
//		push(d);
//	}
//
//	pop();
//	printf("%d ", pop());
//	pop();
//	printf("%d", pop());
//
//	return 0;
//
//}

// queue 1561

//#include <stdio.h>
//
//#define Q_SIZE 10
//int my_queue[Q_SIZE];
//int front = 0;
//int rear = 0;
//
//void enqueue(int v)
//{
//	if (front == (rear + 1) % Q_SIZE)
//	{
//		return;
//	}
//	my_queue[rear] = v;
//	rear = (rear + 1) % Q_SIZE;
//}
//int dequeue()
//{
//	if (front == rear)
//	{
//		return -999;
//	}
//	int res = my_queue[front];
//	front = (front + 1) % Q_SIZE;
//	return res;
//}
//
//
//int main(void) {
//
//	int d;
//
//	while (1) {
//		scanf("%d", &d);
//		if (d < 0) {
//			break;
//		}
//		enqueue(d);
//	}
//
//	dequeue();
//	printf("%d ", dequeue());
//	dequeue();
//	printf("%d", dequeue());
//
//	return 0;
//
//}

// add dll & del dll 1562

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//	struct node* prev;
//};
//struct node* head = 0;
//
//void addToDLL(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = nnode->prev = 0;
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
//	nnode->prev = temp;
//}
//
//void delFromDLL(int _data)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* temp = head;
//	while (temp != 0)
//	{
//		if (temp->data == _data)
//		{
//			if (temp->next != 0)
//			{
//				if (temp == head)
//				{
//					head = head->next;
//					head->prev = 0;
//					free(temp);
//					return;
//				}
//				else
//				{
//					temp->prev->next = temp->next;
//					temp->next->prev = temp->prev;
//					free(temp);
//					return;
//				}
//			}
//			else
//			{
//				if (temp == head)
//				{
//					free(temp);
//					head = 0;
//					return;
//				}
//				else
//				{
//					temp->prev->next = 0;
//					free(temp);
//					return;
//				}
//			}
//		}
//		else
//		{
//			temp = temp->next;
//		}
//	}
//
//	return;
//}
//
//int main(void) {
//
//	int d;
//	int i;
//	struct node* k = 0;
//
//	while (1) {
//		scanf("%d", &d);
//		if (d < 0) {
//			break;
//		}
//		addToDLL(d);
//	}
//
//	delFromDLL(45);
//	delFromDLL(50);
//	delFromDLL(60);
//
//	k = head;
//	for (i = 0; i < -d; i++) {
//		k = k->next;
//	}
//	k = k->prev;
//	printf("%d", k->data);
//	return 0;
//}

// addbst 1579

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
//void addToBST(int _data) {
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
//		if (temp->data > _data)
//		{
//			if (temp->left == 0)
//			{
//				temp->left = nnode;
//				return;
//			}
//			temp = temp->left;
//		}
//		if (temp->data < _data)
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
//
//int main(void) {
//
//	int d = 0;
//	int i;
//
//	for (i = 0; i < 5; i++) {
//		scanf("%d", &d);
//		addToBST(d);
//	}
//
//	printf("%d", root->left->right->data);
//
//	return 0;
//}

/**/


// dll front insert 1580

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//	struct node* prev;
//};
//struct node* head = 0;
//
//void addToDLL(int v)
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
//	struct node* temp = head;
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//	temp->next = nnode;
//	nnode->prev = temp;
//}
//
//void insertIntoDLL(int _a, int _b)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* temp = head;
//
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _b;
//	nnode->next = nnode->prev = 0;
//
//	while (temp != 0)
//	{
//		if (temp->data == _a)
//		{
//			if (temp == head)
//			{
//				nnode->next = head;
//				head->prev = nnode;
//				head = nnode;
//				return;
//			}
//			else
//			{
//				nnode->prev = temp->prev;
//				nnode->next = temp;
//				temp->prev->next = nnode;
//				temp->prev = nnode;
//				return;
//			}
//		}
//		else
//		{
//			temp = temp->next;
//		}
//	}
//	return;
//}
//
//
//int main(void) {
//
//	int d;
//	int i;
//	struct node* k = 0;
//
//	while (1) {
//		scanf("%d", &d);
//		if (d < 0) {
//			break;
//		}
//		addToDLL(d);
//	}
//
//	insertIntoDLL(-d, -d * 10);
//	insertIntoDLL(40, -d * 20);
//
//	printf("%d ", head->data);
//	k = head;
//	while (k->next != 0) {
//		k = k->next;
//	}
//	printf("%d", k->prev->data);
//	return 0;
//}

// sll 1581

//#include <stdio.h> 
//#include <stdlib.h> 
//struct node {
//	int data;
//	struct node* next;
//};
//struct node* head = 0;
//
//void addToSLL(int _d)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _d;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//		return;
//	}
//	struct node* temp = head;
//
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//	temp->next = nnode;
//
//}
//
//void insertIntoSLL(int _a, int _b)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _b;
//	nnode->next = 0;
//
//	struct node* temp = head;
//	while (temp != 0)
//	{
//		if (temp->data == _a)
//		{
//			if (temp->next != 0)
//			{
//				nnode->next = temp->next;
//			}
//
//			temp->next = nnode;
//			return;
//		}
//		temp = temp->next;
//	}
//	return;
//}
//
//void delFromSLL(int _d)
//{
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
//		if (temp->data == _d)
//		{
//			if (temp->next != 0)
//			{
//				if (temp == head)
//				{
//					head = head->next;
//					free(temp);
//					return;
//				}
//				else
//				{
//					temp_p->next = temp->next;
//					free(temp);
//					return;
//				}
//			}
//			else
//			{
//				if (temp == head)
//				{
//					free(temp);
//					head = 0;
//					return;
//				}
//				else
//				{
//					temp_p->next = 0;
//					free(temp);
//					return;
//				}
//			}
//		}
//		else
//		{
//			temp_p = temp;
//			temp = temp->next;
//		}
//	}
//	return;
//}
//
//int main(void) {
//	int d;
//	int i;
//	struct node* k = 0;
//	while (1) {
//		scanf("%d", &d); if (d < 0) {
//			break;
//		}
//		addToSLL(d);
//	}
//
//	insertIntoSLL(-d, -d * 10);
//	insertIntoSLL(40, -d * 20);
//
//	delFromSLL(-d);
//	delFromSLL(-d / 2);
//
//	printf("%d ", head->data);
//	k = head; while (k->next != 0) {
//		k = k->next;
//	}
//	printf("%d", k->data); return 0;
//}

// BST  1586

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
//void addToBST(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->left = nnode->right = 0;
//
//	struct node* temp = root;
//
//	if (root == 0)
//	{
//		root = nnode;
//		return;
//	}
//
//	while (1)
//	{
//		if (temp->data > _data)
//		{
//			if (temp->left == 0)
//			{
//				temp->left = nnode;
//				return;
//			}
//			temp = temp->left;
//		}
//		if (temp->data < _data)
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
//void delFromBST(int _data)
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
//		if (temp->data == _data)
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
//				if (temp_p->right = temp)
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
//				if (temp_p->right = temp)
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
//				if (k_p->right == k)
//				{
//					k_p->right = k->right;
//					free(k);
//					return;
//				}
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
//}
//
//int main(void) {
//
//	int d = 0;
//	int i;
//
//	for (i = 0; i < 6; i++) {
//		scanf("%d", &d);
//		addToBST(d);
//	}
//	scanf("%d", &d);
//	delFromBST(d);
//
//	scanf("%d", &d);
//	delFromBST(d);
//
//	printf("%d", root->right->data);
//
//	return 0;
//}

// MST kruskal 1591 사이클 확인

//#include <stdio.h>
//
//
//#pragma warning (disable:4996)
//
//#define NV 5    // number of vertices <-- 이것은 고정이니 수정 금지
//int visited[NV] = { 0 };
//
//int check[NV][NV] = { 0 }; // 지나간 버텍스 체크
//int check_ver[NV][NV] = { 0 }; // 사이클로 이미 확인된 버텍스 확인
//
//
//
//void addEdge(int graph[][NV], int v1, int v2, int w) {
//    graph[v1][v2] = w;
//    graph[v2][v1] = w;
//}
//
//void MST_BY_KRUSKAL(int graph[][NV]) {
//    int family[NV] = { 0,1,2,3,4 };
//
//    for (int cnt = 0; cnt < NV - 1; cnt++)
//    {
//        int v1 = -1;
//        int v2 = -1;
//        int mindist = 9999;
//
//        for (int i = 0; i < NV; i++)
//        {
//            for (int j = i + 1; j < NV; j++)
//            {
//                if (family[i] != family[j] && graph[i][j] && graph[i][j] < mindist)
//                {
//                    mindist = graph[i][j];
//                    v1 = i;
//                    v2 = j;
//
//                }
//
//                else if (graph[i][j] && !check[i][j] && family[i] == family[j] && mindist > graph[i][j])
//                {
//                    // 그래프 이어져있고 두개가 이어져있다고는 확인이 안됐고
//                    // 같은 패밀리이며 mindist보다 graph[i][j]값이 작을때 들어옴
//
//                    if (check_ver[i][j] == 0 || check_ver[j][i] == 0) // 사이클이라고 확인이 안됐으면 실행
//                    {
//                        printf("%d\n", i + j);
//                    }
//                    check_ver[i][j] = 1; // 지나간 사이클의 두 버텍스는 1로 마킹
//                    check_ver[j][i] = 1;
//
//                }
//            }
//        }
//
//        check[v1][v2] = 1;
//        check[v2][v1] = 1;
//
//
//
//        int old_fam = family[v2];
//        int new_fam = family[v1];
//
//        for (int k = 0; k < NV; k++)
//        {
//            if (family[k] == old_fam)
//            {
//                family[k] = new_fam;
//            }
//        }
//
//
//
//    }
//}
//
//
//int main(void) {
//
//    int v1 = 0;
//    int v2 = 0;
//    int w = 0;
//    int graph[NV][NV] = { 0 };
//
//    while (1) {
//
//        scanf("%d %d %d", &v1, &v2, &w);
//
//        if (v1 < 0) {
//            break;
//        }
//        addEdge(graph, v1, v2, w);
//
//    }
//
//    MST_BY_KRUSKAL(graph);
//
//    return 0;
//
//}