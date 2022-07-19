//// 하노이

//#include <stdio.h>
//
//void hanoi(int _n,int _s,int _t,int _e)
//{
//	if (_n == 1)
//	{
//		printf("%d에서 %d로\n", _s, _e);
//		return;
//	}
//
//	hanoi(_n - 1, _s, _e, _t);
//	hanoi(1, _s, _t, _e);
//	hanoi(_n - 1, _t, _s, _e);
//
//}
//
//int main()
//{
//	hanoi(3, 1, 2, 3);
//}

//sll

//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning (disable : 4996)
//
//struct node {
//	int data;
//	struct node* next;
//};
//
//struct node* head = 0;
//
//void addlist(int _data)
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
//
//	else
//	{
//		struct node* temp = head;
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		temp->next = nnode;
//		return;
//	}
//}
//
//void showlist()
//{
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		struct node* temp = head;
//		while (temp != 0)
//		{
//			printf("%d --> ", temp->data);
//			temp = temp->next;
//		}
//		printf("\n----------\n");
//		return;
//	}
//}
//
//void clear()
//{
//	struct node* temp = head;
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		while (head != 0)
//		{
//			head = head->next;
//			free(temp);
//			temp = head;
//		}
//	}
//}
//
//void insertlist(int _where,int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		struct node* temp = head;
//
//		while (temp->data != _where)
//		{
//			temp = temp->next;
//		}
//		if (temp->next != 0)
//		{
//			nnode->next = temp->next;
//		}
//		temp->next = nnode;
//		return;
//	}
//	
//}
//
//void dellist(int _data)   // 다지우는 sll
//{
//	struct node* temp = head;
//	struct node* temp_prev = 0;
//	struct node* del = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//
//	while (temp != 0)
//	{
//		if (temp->data == _data)
//		{
//			if (temp == head)
//			{
//				if (temp->next != 0)
//				{
//					del = head;
//					head = head->next;
//					temp = head;
//					free(del);
//					continue;
//				}
//				else
//				{
//					free(head);
//					head = 0;
//					return;
//				}
//			}
//			else
//			{
//				del = temp;
//				temp_prev->next = temp->next;
//				temp = temp->next;
//				free(del);
//				continue;
//
//			}
//		}
//
//		temp_prev = temp;
//		temp = temp->next;
//	}
//
//	return;
//	
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		int data = 0;
//		scanf("%d", &data);
//		addlist(data);
//	}
//	showlist();
//
//	/*int _d = 0;
//	int _w = 0;
//
//
//	scanf("%d", &_d);
//	scanf("%d", &_w);
//
//	insertlist(_d, _w);
//	showlist();
//
//	printf("\n");*/
//
//	int del = 0;
//	scanf("%d", &del);
//
//	dellist(del);
//	
//	showlist();
//}

//dll

//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning(disable:4996)
//
//
//struct node {
//	int data;
//	struct node* prev;
//	struct node* next;
//};
//
//struct node* head = 0;
//
//void addlist(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->prev = nnode->next = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//		return;
//	}
//
//	else
//	{
//		struct node* temp = head;
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		temp->next = nnode;
//		nnode->prev = temp;
//		return;
//	}
//}
//
//void showlist()
//{
//	struct node* temp = head;
//
//	if (head == 0)
//	{
//		printf("-999");
//		return ;
//	}
//
//	while (temp != 0)
//	{
//		printf("%d ",temp->data);
//		temp = temp->next;
//	}
//	return;
//}
//
//void insertlist(int _where, int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->prev = nnode->next = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//
//	struct node* temp = head;
//
//	while (temp->data != _where)
//	{
//		temp = temp->next;
//	}
//
//	if (temp->next == 0)
//	{
//		temp->next = nnode;
//		nnode->prev = temp;
//		return;
//	}
//
//	else
//	{
//		nnode->next = temp->next;
//		nnode->prev = temp;
//		nnode->next->prev = nnode;
//		temp->next = nnode;
//		return;
//	}
//	
//
//}
//
//void dellist(int _data)
//{
//	struct node* temp = head;
//	struct node* del = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//
//	else
//	{
//		while (temp != 0)
//		{
//			if (temp->data == _data)
//			{
//				if (temp == head)
//				{
//					if (head->next != 0)
//					{
//						del = head;
//						head = head->next;
//						head->prev = 0;
//						temp = head;
//						free(del);
//						continue;
//					}
//					else
//					{
//						free(head);
//						head = 0;
//					}
//				}
//				else
//				{
//					if (temp->next != 0)
//					{
//						del = temp;
//						temp->prev->next = temp->next;
//						temp->next->prev = temp->prev;
//						temp = temp->next;
//						free(del);
//						continue;
//					}
//					else
//					{
//						temp->prev->next = 0;
//						free(temp);
//						return;
//					}
//				}
//			}
//
//			temp = temp->next;
//		}
//	}
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		int data = 0;
//		scanf("%d", &data);
//		addlist(data);
//	}
//
//	/*int _d = 0;
//	int _w = 0;
//
//
//	scanf("%d", &_d);
//	scanf("%d", &_w);
//
//	insertlist(_d, _w);
//	showlist();
//
//	printf("\n");*/
//
//
//	int del = 0;
//	scanf("%d", &del);
//
//	dellist(del);
//	
//	showlist();
//}

//stack

//#include <stdio.h>
//#include <stdlib.h>
//
//#define stk_siz 5
//
//int stk[stk_siz];
//int top = -1;
//
//int isfull()
//{
//	return ((stk_siz - 1) == top);
//}
//
//int isempty()
//{
//	return (top == -1);
//}
//
//void push(int _data)
//{
//	if(isfull())
//	{
//		return;
//	}
//
//	top++;
//	stk[top] = _data;
//	return;
//}
//
//int pop()
//{
//	if (isempty())
//	{
//		return -999;
//	}
//
//	int res = stk[top];
//	top--;
//	return res;
//
//}
//
//int main()
//{
//	push(5);
//	push(3);
//	push(1);
//
//
//	printf("%d ", pop());
//	printf("%d ", pop());
//	printf("%d ", pop());
//
//}

//queue

//#include <stdio.h>
//#include <stdlib.h>
//
//#define que_siz 6
//
//int que[que_siz];
//int front = 0;
//int rear = 0;
//
//int isfull()
//{
//	return (front == ((rear + 1) % que_siz));
//}
//
//int isempty()
//{
//	return (front == rear);
//}
//
//void enqueue(int _data)
//{
//	if (isfull())
//	{
//		return;
//	}
//
//	que[rear] = _data;
//	rear = (rear + 1) % que_siz;
//	return;
//
//}
//
//int dequeue()
//{
//	if (isempty())
//	{
//		return -999;
//	}
//
//	int res = que[front];
//	front = (front + 1) % que_siz;
//	return res;
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
//
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//}

// 후위수식

//#include <stdio.h>
//#include <stdlib.h>
//
//#define stk_size 20
//
//int stk[stk_size];
//int top = -1;
//
//void push(int _data)
//{
//	if (top == (stk_size - 1))
//	{
//		return;
//	}
//	top++;
//	stk[top] = _data;
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		return -999;
//	}
//	int res = stk[top];
//	top--;
//	return res;
//}
//
//int main()
//{
//	char str[] = "82*3-";
//	int idx = 0;
//
//	while (str[idx] != '\0')
//	{
//		//숫자면 푸시
//		if ('0' <= str[idx] && str[idx] <= '9')
//		{
//			push((int)(str[idx] - '0'));
//		}
//
//		//연산자면 계산
//
//		else
//		{
//			int a = 0;
//			int b = 0;
//
//			b = pop();
//			a = pop();
//			switch (str[idx])
//			{
//			case '+':
//				push(a + b);
//				break;
//			case '-':
//				push(a - b);
//				break;
//			case '*':
//				push(a * b);
//				break;
//			case '/':
//				push(a / b);
//				break;
//
//			default:
//				printf("뭐임\n");
//				return 0;      // 이거 리턴값 지정 중요
//			}
//		}
//
//		idx++;
//	}
//
//	printf("%d \n", pop());
//	return 0;
//}

// 후위수식으로 만들기

//#include <stdio.h>
//#include <stdlib.h>
//
//#define stk_siz 20
//
//char stk[stk_siz];
//int top = -1;
//
//void push(int _data)
//{
//	if (top == (stk_siz - 1))
//	{
//		return;
//	}
//
//	top = top + 1;
//	stk[top] = _data;
//	return;
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		return -999;
//	}
//	int res = stk[top];
//	top--;
//	return res;
//}
//
//int main()
//{
//	//좌에서 우로 읽어가며
//	//여는 괄호는 스택에 푸쉬
//	//숫자는 그냥 화면에 출력 
//	//닫는 괄호의 경우 여는 괄호가 나올때까지 팝하면서 그 결과를 출력
//	//*와/ 경우에는 무조건 푸쉬 
//	//+와- 경우에는 stk[top]에 있는것이 * /면 
//	//* /가 먼저 계산되어야 하니까 곱하기 나누기 출력, 지금 들어온거 입력
//
//
//
//	char str[] = "8*7*6+3";
//	int idx = 0;
//
//	while (str[idx] != '\0')
//	{
//		if (stk[idx] == '(')
//		{
//			push(str[idx]);
//		}
//		else if (str[idx] >= '0' && str[idx] <= '9')
//		{
//			printf("%c", str[idx]);
//		}
//		else if (str[idx] == ')')
//		{
//			while (1)
//			{
//				char res = pop();
//				if (res == '(')
//				{
//					break;
//				}
//				else
//				{
//					printf("%c", res);
//				}
//			}
//		}
//		else if (str[idx] == '*' || str[idx] == '/')
//		{
//			push(str[idx]);
//		}
//		else
//		{
//			if (stk[top] == '*' || stk[top] == '/')
//			{
//				while ((stk[top] == '*' || stk[top] == '/'))     // 이거 와일문으로 써주는게 맞을듯
//				{
//					printf("%c", pop());
//				}
//				push(str[idx]);
//			}
//			else {
//				push(str[idx]);
//			}
//		}
//		idx++;
//	}
//
//	while (top != -1)
//	{
//		printf("%c", pop());
//	}
//
//}

//BST

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
//
//	struct node* temp = root;
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
//			else
//			{
//				temp = temp->left;
//			}
//		}
//		if (temp->data < _data)
//		{
//			if (temp->right == 0)
//			{
//				temp->right = nnode;
//				return;
//			}
//			else
//			{
//				temp = temp->right;
//			}
//		}
//	}
//}
//
//struct node* findBST(int _data)
//{
//	struct node* temp = root;
//
//	while (1)
//	{
//		if (temp == 0)
//		{
//			return 0;
//		}
//		if (temp->data == _data)
//		{
//			return temp;
//		}
//		if (temp->data > _data)
//		{
//			temp = temp->left;
//		}
//		if (temp->data < _data)
//		{
//			temp = temp->right;
//		}
//	}
//}
//
//int cntBST(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	return 1 + cntBST(_r->left) + cntBST(_r->right);
//}
//
//int cntTer(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//	if (_r->left == 0 && _r->right == 0)
//	{
//		return 1;
//	}
//	return cntTer(_r->left) + cntTer(_r->right);
//}
//
//int measurheight(struct node* _r)
//{
//	int left_h = 0;
//	int right_h = 0;
//
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	left_h = measurheight(_r->left);
//	right_h = measurheight(_r->right);
//
//	return 1 + ((left_h > right_h) ? left_h : right_h);
//}
//
//void inorder(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return;
//	}
//
//	inorder(_r->left);
//	printf("%d ", _r->data);
//	inorder(_r->right);
//}
//
//
//// del은 많은걸 따져야 해
//// 루트 비었어?
//// 터미널 노드인데 루트니 왼쪽에 달렸니 오른쪽에 달렸니
//// 자식이 하나인데 루트니 왼쪽에 달럈니 오른쪽에 달렸니 니 자식은 왼쪽에 있니 오른쪽에 있니
//// 자식이 둘인데 헤드니 오른쪽의 제일 막내는 누구니 그 막내의 부모는 누구니   
////
//
//void delBST(int _data, struct node* _r)
//{
//	struct node* t = _r;
//	struct node* t_p = 0;
//
//	if (_r == 0)
//	{
//		return;
//	}
//
//	while (1)
//	{
//		if (t == 0)
//		{
//			return;
//		}
//
//		if (t->data == _data)
//		{
//			if (t->left == 0 && t->right == 0) // teminal
//			{
//				if (t == root)
//				{
//					root = 0;
//					free(t);
//					return;
//				}
//
//				if (t_p->left == t)
//				{
//					t_p->left = 0;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = 0;
//					free(t);
//					return;
//				}
//			}
//
//			if (t->left != 0 && t->right == 0) // left
//			{
//				if (t == root)
//				{
//					root = root->left;
//					free(t);
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = t->left;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = t->left;
//					free(t);
//					return;
//				}
//			}
//
//			if (t->right != 0 && t->left == 0) //right
//			{
//				if (t == root)
//				{
//					root = root->left;
//					free(t);
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = t->right;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = t->right;
//					free(t);
//					return;
//				}
//			}
//
//			if (t->left != 0 && t->right != 0)
//			{
//				struct node* r = t->right;
//				struct node* r_p = t;
//
//				while (r->left != 0)
//				{
//					r_p = r;
//					r = r->left;
//				}
//
//				t->data = r->data;
//
//				if (r_p->left == r)
//				{
//					r_p->left = r->right;
//					free(r);
//					return;
//				}
//				if (r_p->right == r)
//				{
//					r_p->right = r->right;
//					free(r);
//					return;
//				}
//
//			}
//		}
//		else if (_data < t->data)
//		{
//			t_p = t;
//			t = t->left;
//		}
//		else if (_data > t->data)
//		{
//			t_p = t;
//			t = t->right;
//		}
//	}
//
//}
//
//
//
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
//
//	delBST(10, root);
//
//	inorder(root);
//
//}

//sll

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
//void addlist(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//
//	nnode->data = _data;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//	}
//	else
//	{
//		struct node* temp = head;
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		temp->next = nnode;
//		return;
//	}
//}
//
//void clearlist()
//{
//	struct node* temp = head;
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		while (head != 0)
//		{
//			head = head->next;
//			free(temp);
//			temp = head;
//
//		}
//		return;
//	}
//}
//
//void show()
//{
//	struct node* temp = head;
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		while (temp != 0)
//		{
//			printf("%d ", temp->data);
//			temp = temp->next;
//		}
//		return;
//	}
//}
//
//void insertsll(int _data, int _where)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//
//	struct node* temp = head;
//	struct node* temp_prev = 0;
//
//	while (temp != 0)
//	{
//		if (temp->data == _where)
//		{
//			nnode->next = temp->next;
//			temp->next = nnode;
//			return;
//		}
//		temp = temp->next;
//	}
//}
//
//void delsll(int _data)
//{
//	struct node* temp = head;
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		struct node* temp_prev = 0;
//		while (temp != 0)
//		{
//			if (temp->data == _data)
//			{
//				if (temp == head)
//				{
//					head = head->next;
//					free(temp);
//					return;
//				}
//				else if (temp->next == 0)
//				{
//					temp_prev->next = 0;
//					free(temp);
//					return;
//				}
//				else
//				{
//					temp_prev->next = temp->next;
//					free(temp);
//					return;
//				}
//			}
//
//
//
//			temp_prev = temp;
//			temp = temp->next;
//		}
//	}
//}
//
//int main()
//{
//	addlist(10);
//	addlist(20);
//	addlist(30);
//	addlist(40);
//	addlist(50);
//
//	delsll(30);
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
//void addlist(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = nnode->prev = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//	}
//	else
//	{
//		struct node* temp = head;
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		temp->next = nnode;
//		nnode->prev = temp;
//		return;
//	}
//}
//
//void show()
//{
//	struct node* temp = head;
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		while (temp != 0)
//		{
//			printf("%d ", temp->data);
//			temp = temp->next;
//		}
//		return;
//	}
//}
//
//void addlist(int _where,int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = nnode->prev = 0;
//
//	if (head == 0)
//	{
//		return;
//	}
//	else
//	{
//		struct node* temp = head;
//		while (temp != 0)
//		{
//			if (temp->data == _where)
//			{
//				if (temp->next == 0)
//				{
//					nnode->prev = temp;
//					temp->next = nnode;
//					nnode->next = 0;
//					return;
//				}
//				else
//				{
//					nnode->prev = temp;
//					nnode->next = temp->next;
//					nnode->next->prev = nnode;
//					temp->next = nnode;
//					return;
//				}
//			}
//
//			temp = temp->next;
//		}
//	}
//}
//
//void dellist(int _data)
//{
//	if (head == 0)
//	{
//		return;
//	}
//
//	else
//	{
//		struct node* temp = head;
//		while (temp != 0)
//		{
//			if (temp->data == _data)
//			{
//				if (temp == head)
//				{
//					head = head->next;
//					free(temp);
//					temp = head;
//					return;
//				}
//
//				else if (temp->next != 0)
//				{
//					temp->prev->next = temp->next;
//					temp->next->prev = temp->prev;
//					free(temp);
//					return;
//				}
//				else
//				{
//					temp->prev->next = 0;
//					free(temp);
//					return;
//				}
//			}
//			temp = temp->next;
//		}
//	}
//}
//
//int main()
//{
//	addlist(10);
//	addlist(20);
//	addlist(30);
//	addlist(40);
//	addlist(50);
//	addlist(60);
//	
//	dellist(50);
//
//	show();
//}

//stk

//#include <stdio.h>
//#include <stdlib.h>
//
//#define stk_size 5
//
//int stk[stk_size];
//
//int top = -1;
//
//void push(int _data)
//{
//	if (top == (stk_size - 1))
//	{
//		return;
//	}
//	else
//	{
//		top++;
//		stk[top] = _data;
//		return;
//	}
//
//}
//
//int pop()
//{
//	if (top == -1)
//	{
//		return -999;
//	}
//
//	else
//	{
//		int cnt = stk[top];
//		top = top - 1;
//		return cnt;
//	}
//}
//
//int main()
//{
//	push(10);
//	push(20);
//	push(30);
//	push(40);
//
//	printf("%d ", pop());
//	printf("%d ", pop());
//	printf("%d ", pop());
//	printf("%d ", pop());
//	printf("%d ", pop());
//
//
//}

//que

//#include <stdio.h>
//#include <stdlib.h>
//
//#define que_siz 5
//
//int queue[que_siz];
//
//int rear = 0;
//int front = 0;
//
//void enqueue(int _data)
//{
//	if (((rear + 1) % que_siz) == front)
//	{
//		return;
//	}
//
//	else
//	{
//		queue[rear] = _data;
//		rear = (rear + 1) % que_siz;
//		return;
//	}
//
//}
//
//int dequeue()
//{
//	if (rear == front)
//	{
//		return -999;
//	}
//	else
//	{
//		int res = queue[front];
//		front = (front + 1) % que_siz;
//		return res;
//	}
//}
//
//int main()
//{
//	enqueue(10);
//	enqueue(20);
//	enqueue(30);
//	enqueue(40);
//	enqueue(50);
//
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//	printf("%d ", dequeue());
//
//}

//BST
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
//
//	else
//	{
//		struct node* temp = root;
//		while (1)
//		{
//			if (temp->data < _data)
//			{
//				if (temp->right == 0)
//				{
//					temp->right = nnode;
//					return;
//				}
//				else
//				{
//					temp = temp->right;
//				}
//			}
//
//			if (temp->data > _data)
//			{
//				if (temp->left == 0)
//				{
//					temp->left = nnode;
//					return;
//				}
//				else
//				{
//					temp = temp->left;
//				}
//			}
//		}
//	}
//}
//
//struct node* findnode(int _data)
//{
//	if (root == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		struct node* temp = root;
//		while (1)
//		{
//			if (temp == 0)
//			{
//				return 0;
//			}
//			if (temp->data < _data)
//			{
//				temp = temp->right;
//			}
//			if (temp->data > _data)
//			{
//				temp = temp->left;
//			}
//			if (temp->data == _data)
//			{
//				return temp;
//			}
//		}
//	}
//}
//
//int cntBST(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//	return 1 + (cntBST(_r->left) + cntBST(_r->right));
//}
//
//int cntTer(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	if (_r->left == 0 && _r->right == 0)
//	{
//		return 1;
//	}
//
//	return cntTer(_r->left) + cntTer(_r->right);
//}
//
//int measurheight(struct node* _r)
//{
//	int left_height = 0;
//	int right_height = 0;
//
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	left_height = measurheight(_r->left);
//	right_height = measurheight(_r->right);
//
//	return 1 + ((left_height > right_height) ? left_height : right_height);
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
////del -> 자식이 없음 
//// 자식이 하나
//// 왼쪽자식 오른쪽자식
//// 자식이 둘
////
//
//void delBST(int _data, struct node* _r)
//{
//	struct node* t = _r;
//	struct node* t_p = 0;
//
//	while (1)
//	{
//		if (t == 0)
//		{
//			return;
//		}
//
//		if (t->data == _data)
//		{
//			if (t->left == 0 && t->right == 0)
//			{
//				if (t == root)
//				{
//					free(root);
//					root = 0;
//					return;
//				}
//				if (t_p->left = t)
//				{
//					t_p->left = 0;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = 0;
//					free(t);
//					return;
//				}
//			}
//
//			if (t->left != 0 && t->right == 0) //left
//			{
//				if (t == root)
//				{
//					root = t->left;
//					free(t);
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = t->left;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = t->left;
//					free(t);
//					return;
//				}
//
//			}
//
//			if (t->left == 0 && t->right != 0) //right
//			{
//				if (t == root)
//				{
//					root = t->right;
//					free(t);
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = t->right;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = t->right;
//					free(t);
//					return;
//				}
//
//			}
//
//			if (t->left != 0 && t->right != 0) //TTT
//			{
//				struct node* k = t->right;
//				struct node* k_p = t;
//
//				while (k->left != 0)
//				{
//					k_p = k;
//					k = k->left;
//				}
//
//				t->data = k->data;
//
//				if (k_p->right == k)
//				{
//					k_p->right = k->right;
//					free(k);
//					return;
//				}
//				if (k_p->left == k)
//				{
//					k_p->left = k->right;
//					free(k);
//;					return;
//				}
//
//			}
//		}
//		else
//		{
//			if (_data > t->data)
//			{
//				t_p = t;
//				t = t->right;
//			}
//			else
//			{
//				t_p = t;
//				t = t->left;
//			}
//		}
//	}
//
//	
//}
//
//
//
//
//
//
//
//
//
//int main()
//{
//	addBST(100);
//	addBST(50);
//	addBST(200);
//	addBST(10);
//	addBST(70);
//	addBST(150);
//
//	delBST(50,root);
//
//	inorder(root);
//
//}

//BST

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
//	nnode->right = nnode->left = 0;
//
//	if (root == 0)
//	{
//		root = nnode;
//		return;
//	}
//	else
//	{
//		struct node* temp = root;
//		while (1)
//		{
//			if (_data < temp->data)
//			{
//				if (temp->left == 0)
//				{
//					temp->left = nnode;
//					return;
//				}
//				temp = temp->left;
//			}
//			else if (_data > temp->data)
//			{
//				if (temp->right == 0)
//				{
//					temp->right = nnode;
//					return;
//				}
//				temp = temp->right;
//			}
//		}
//	}
//}
//
//struct node* findnode(int _data)
//{
//	if (root == 0)
//	{
//		return 0;
//	}
//	else
//	{
//		struct node* temp = root;
//		while (1)
//		{
//			if (temp == 0)
//			{
//				return 0;
//			}
//			if (temp->data == _data)
//			{
//				return temp;
//			}
//			if (_data < temp->data)
//			{
//				temp = temp->left;
//			}
//			if (_data > temp->data)
//			{
//				temp = temp->right;
//			}
//		}
//	}
//}
//
//int cntBST(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	return 1 + cntBST(_r->left) + cntBST(_r->right);
//}
//
//int cntTer(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	if (_r->left == 0 && _r->right == 0)
//	{
//		return 1;
//	}
//
//	return cntTer(_r->left) + cntTer(_r->right);
//
//}
//
//int measurheight(struct node* _r)
//{
//	if (_r == 0)
//	{
//		return 0;
//	}
//
//	int left = measurheight(_r->left);
//	int right = measurheight(_r->right);
//
//	return 1 + ((left > right) ? left : right);
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
//void delBST(int _data, struct node* _r)
//{
//	//
//	// 무자식 
//	// 홑자식 
//	// 쌍자식
//	// 각각이 루트, 본인이 왼쪽인지 오른쪽인지 확인
//	//
//
//	struct node* t = root;
//	struct node* t_p = 0;
//
//	while (1)
//	{
//		if (t == 0)
//		{
//			return;
//		}
//		if (t->data == _data)
//		{
//			if (t->left == 0 && t->right == 0)
//			{
//				if (t == root)
//				{
//					free(root);
//					root = 0;
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = 0;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = 0;
//					free(t);
//					return;
//				}
//			}
//
//			if (t->left != 0 && t->right == 0) //left
//			{
//				if (t == root)
//				{
//					root = t->left;
//					free(t);
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = t->left;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = t->left;
//					free(t);
//					return;
//				}
//			}
//			if (t->left == 0 && t->right != 0) //r
//			{
//				if (t == root)
//				{
//					root = t->right;
//					free(t);
//					return;
//				}
//				if (t_p->left == t)
//				{
//					t_p->left = t->right;
//					free(t);
//					return;
//				}
//				if (t_p->right == t)
//				{
//					t_p->right = t->right;
//					free(t);
//					return;
//				}
//			}
//
//			if (t->left != 0 && t->right != 0)
//			{
//				struct node* k = t->right;
//				struct node* k_p = t;
//
//				while (k->left != 0)
//				{
//					k_p = k;
//					k = k->left;
//				}
//
//				t->data = k->data;
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
//
//
//		}
//		else
//		{
//			t_p = t;
//			if (_data < t->data)
//			{
//				t = t->left;
//			}
//			if (_data > t->data)
//			{
//				t = t->right;
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
//
//	delBST(150, root);
//
//	inorder(root);
//
//}
