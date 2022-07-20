//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning (disable:4996)
//
//struct node {
//	int data;
//	struct node* next;
//	struct node* prev;
//};
//
//struct node* head = 0;
//
//void add(int _data)
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
//	return;
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
//		return;
//	}
//}
//
//void show()
//{
//	if (head == 0)
//	{
//		return;
//	}
//	struct node* temp = head;
//	while (temp != 0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//	return;
//}
//
//void insert(int _a, int _b)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->next = nnode->prev = 0;
//	nnode->data = _b;
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
//		if (temp->data == _a)
//		{
//			if (temp->next != 0)
//			{
//				nnode->next = temp->next;
//				nnode->prev = temp;
//				nnode->next->prev = nnode;
//				temp->next = nnode;
//				return;
//			}
//			else
//			{
//				temp->next = nnode;
//				nnode->prev = temp;
//				return;
//			}
//		}
//		temp = temp->next;
//	}
//	return;
//}
//
//void del(int _data)
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
//			if (temp == head)
//			{
//				head = head->next;
//				if (temp->next != 0)
//				{
//					temp->next->prev = 0;
//				}
//				free(temp);
//				return;
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
//					temp->prev->next = temp->next;
//					temp->next->prev = temp->prev;
//					free(temp);
//					return;
//				}
//			}
//		}
//		temp = temp->next;
//
//	}
//	return;
//}
//
//int main()
//{
//	int k;
//
//	scanf("%d", &k);
//
//	for (int i = 0; i < k; i++)
//	{
//		int data;
//		scanf("%d", &data);
//		add(data);
//
//	}
//
//	int d;
//
//	scanf("%d", &k);
//	del(k);
//
//
//
//	show();
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//#define Q_S  10
//int que[Q_S];
//int rear = 0;
//int front = 0;
//
//void enqueue(int _data)
//{
//	if ((rear + 1) % Q_S == front)
//	{
//		return;
//	}
//
//	que[rear] = _data;
//	rear=(rear+1)%Q_S;
//	return;
//}
//int dequeue()
//{
//	if (rear == front)
//	{
//		return -999;
//	}
//
//	int res = que[front];
//	front=(front+1)%Q_S;
//	return res;
//
//}
//
//#define stk_siz 10
//int stk[stk_siz];
//int top = -1;
//
//void push(int _data)
//{
//	if ((top - 1) == stk_siz)
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
//	enqueue(1);
//	enqueue(2);
//	enqueue(3);
//	enqueue(4);
//	enqueue(5);
//
//
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", dequeue());
//	}
//
//	printf("\n");
//
//	push(1);
//	push(2);
//	push(3);
//	push(4);
//	push(5);
//
//	for (int i = 0; i < 6; i++)
//	{
//		printf("%d ", pop());
//	}
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning(disable:4996)
//
//struct node {
//	int data;
//	struct node* left;
//	struct node* right;
//};
//
//struct node* root = 0;
//
//void add(int _data)
//{
//	struct node* nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->left = nnode->right = 0;
//	nnode->data = _data;
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
//
//	inorder(_r->left);
//	printf("%d ", _r->data);
//	inorder(_r->right);
//}
//
//void del(int _data, struct node* _r)
//{
//
//
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
//				if (t == _r)
//				{
//					free(_r);
//					_r = 0;
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
//			if (t->left != 0 && t->right == 0)
//			{
//				if (t == _r)
//				{
//					_r = _r->left;
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
//			if (t->left == 0 && t->right != 0)
//			{
//				if (t == _r)
//				{
//					_r = _r->right;
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
//			}
//
//		}
//
//
//
//
//
//		else
//		{
//			if (t->data < _data)
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
//}
//
//int main()
//{
//	add(100);
//	add(50);
//	add(200);
//	add(10);
//	add(70);
//	add(150);
//	add(250);
//	add(5);
//
//	del(10, root);
//
//	inorder(root);
//
//}


// git start 220719 
// test line 

// git produce 220720
// test line