// SLL 

/* #include <stdio.h>
#include <stdlib.h>

#pragma warning (disable : 4996)

struct node {
	int data;
	struct node* next;
};

struct node* head = 0;

void addlist(int _data)
{
	struct node* nnode = 0;
	nnode = (struct node*)malloc(sizeof(struct node));
	nnode->data = _data;
	nnode->next = 0;

	if (head == 0)
	{
		head = nnode;
		return;
	}

	struct node* temp = head;
	while (temp->next != 0)
	{
		temp = temp->next;
	}
	temp->next = nnode;
	return;
}

void show()
{
	if (head == 0)
	{
		return;
	}
	struct node* temp = head;
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



void dellist(int _data)
{
	struct node* temp = head;
	struct node* temp_prev = 0;
	struct node* del = 0;

	if (head == 0)
	{
		return;
	}

	while (temp != 0)
	{
		if (temp->data == _data)
		{
			if (temp == head)
			{
				del = head;
				head = head->next;
				temp = head;
				free(del);
				continue;
			}
			else
			{
				temp_prev->next = temp->next;
				del = temp;
				temp = temp->next;
				free(del);
				continue;

			}

		}

		temp_prev = temp;
		temp = temp->next;
	}
}

int main()
{
	int n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		addlist(data);
	}

	int del = 0;
	scanf("%d", &del);

	dellist(del);

	show();
}

*/

/* #include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

struct node {
	int data;
	struct node* next;
};

struct node* head = 0;

void addToList(int _data)
{
	struct node* new_node = 0;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _data;
	new_node->next = 0;

	if (head == 0)
	{
		head = new_node;
		return;
	}
	else
	{
		struct node* temp = head;

		while (temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = new_node;
		return;
	}

}

void reversshow()
{
	struct node* temp = head;
	struct node* temp2 = head;

	while (temp->next != 0)
	{
		temp = temp->next;
	}

	while (temp != head)
	{
		while (temp2->next != temp)
		{
			temp2 = temp2->next;
		}
		printf("%d ", temp->data);
		temp = temp2;
		temp2 = head;
	}
	printf("%d", head->data);
	return;
}

void inserlist(int _where, int _data)
{
	struct node* new_node = 0;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _data;
	new_node->next = 0;

	if (head == 0)
	{
		printf("삽입할 노드가 없습니다.\n");
		return;
	}

	else
	{
		struct node* temp = head;

		while (temp != 0)
		{
			if (temp->data == _where)
			{
				if (temp->next == 0)
				{
					temp->next = new_node;
					new_node->next = 0;
					return;
				}

				new_node->next = temp->next;
				temp->next = new_node;
				return;


			}

			temp = temp->next;
		}

	}

}
void show()
{
	if (head == 0)
	{
		return;
	}
	struct node* temp = head;
	while (temp != 0)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}




int main()
{
	int n = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		addToList(data);
	}

	int where = 0;
	int what = 0;

	scanf("%d %d", &where, &what);
	inserlist(where, what);

	show();


} */

// DLL

/* #include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

struct node {
	int data;
	struct node* next;
	struct node* prev;
};

struct node* head = 0;

void addlist(int _data)
{
	struct node* nnode = 0;
	nnode = (struct node*)malloc(sizeof(struct node));
	nnode->data = _data;
	nnode->next = nnode->prev = 0;

	if (head == 0)
	{
		head = nnode;
		return;
	}
	else
	{
		struct node* temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = nnode;
		nnode->prev = temp;
		return;
	}

}

void show()
{
	struct node* temp = head;

	if (temp == 0)
	{
		printf("-999");
		return;
	}
	else
	{
		while (temp != 0)
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}
		return;
	}
}

void dellist(int _data)
{
	if (head == 0)
	{
		return;
	}
	else
	{
		struct node* temp = head;
		struct node* del = 0;

		while (temp != 0)
		{
			if (temp->data == _data)
			{
				if (temp == head)
				{
					del = head;
					head = head->next;

					if (head != 0)            // 이거 젤 중요 별표 다섯개
						head->prev = 0;       // 노드가 없는거는 접근이 안되니까 안돼

					temp = head;
					free(del);
					continue;
				}
				else if (temp->next == 0)
				{
					temp->prev->next = 0;
					free(temp);
					return; // 마지막 노드이므로, return; 한다
				}
				else
				{
					del = temp;
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;

					temp = temp->next;
					free(del);
					continue;
				}


			}
			temp = temp->next;

		}
	}
}

void insertlist(int _where, int _what)
{
	struct node* nnode = 0;
	nnode = (struct node*)malloc(sizeof(struct node));
	nnode->data = _what;
	nnode->next = nnode->prev = 0;

	if (head == 0)
	{
		return;
	}
	struct node* temp = head;

	while (temp != 0)
	{
		if (temp->data == _where)
		{
			if (temp->next == 0)
			{
				temp->next = nnode;
				nnode->prev = temp;
				nnode->next = 0;
				return;
			}
			nnode->prev = temp;
			nnode->next = temp->next;
			temp->next = nnode;
			nnode->next->prev = nnode;
		}


		temp = temp->next;
	}


}

int main()
{
	int n = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int data;
		scanf("%d", &data);
		addlist(data);
	}


	int wh = 0;
	int wha = 0;

	scanf("%d %d", &wh, &wha);

	insertlist(wh, wha);

	show();

}
*/

// 배열 stack

// #include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning (disable : 4996)
//
//#define STK_SIZE 100
//
//int stk[STK_SIZE];
//int top = -1;
//
//int pop();
//
//int isfull()
//{
//	return (top == (STK_SIZE - 1));
//}
//
//int isempty()
//{
//	return (top == -1);
//}
//
//void push(int _data)
//{
//	if (isfull())
//	{
//		return;
//	}
//
//	
//
//	/*if (_data == 100)
//	{
//		int sum = 0;
//		while (!isempty())
//		{
//			sum = sum + pop();
//		}
//		top++;
//		stk[top] = sum;
//		return;
//
//	}*/
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
//	int res = 0;
//	res = stk[top];
//	top--;
//	return res;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	int i = 0;
//
//	for ( i = 0; i < n; i++)
//	{
//		int data = 0;
//		scanf("%d", &data);
//		if (data == 100)            // 이 방법이랑 위에 함수 건드는 두가지 방법 있음
//		{
//			int sum = 0;
//			while (!isempty())
//			{
//				sum = sum + pop();
//			}
//			push(sum);
//			continue;
//		}
//		push(data);
//	}
//
//	while (!isempty())         // 이거 혼자 생각 못함
//	{
//		printf("%d ", pop());
//	}
//
//}


// 배열 큐

// #include <stdio.h>
//
//#pragma warning (disable : 4996)
//
//#define QUE_SIZ 7
//
//int que[QUE_SIZ];
//
//int front = 0;
//int rear = 0;
//
//int dequeue();
//
//int isfull()
//{
//	return (front == (rear + 1) % QUE_SIZ);
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
//	if (_data == 100)
//	{
//		int sum = 0;
//		while (!isempty())
//		{
//			sum = sum + dequeue();
//		}
//		que[rear] = sum;
//		rear = ((rear + 1) % QUE_SIZ);
//		return;
//	}
//
//	que[rear] = _data;
//	rear=((rear+1)% QUE_SIZ);
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
//	front=((front+1)% QUE_SIZ);
//	return res;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//
//	for (i = 0; i < n; i++)
//	{
//		int data = 0;
//		scanf("%d", &data);
//
//		enqueue(data);
//	}
//
//	while (!isempty())
//	{
//		printf("%d ", dequeue());
//	}
//}   


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#if 0

struct DLL_node {
	int data;
	struct DLL_node* next;
	struct DLL_node* prev;
};

struct DLL_node* head = 0;

int isStackEmpty()   // full 함수는 차피 리스트니까 안만들어도 댐
{
	return (head == 0);
}

void addToDLL(int _data)
{
	struct DLL_node* temp = head;
	struct DLL_node* new_node = (struct DLL_node*)malloc(sizeof(struct DLL_node));

	new_node->data = _data;
	new_node->next = new_node->prev = 0;

	if (head == 0)
	{
		head = new_node;
		return;
	}

	else
	{
		while (temp->next != 0)
		{
			temp = temp->next;
		}
		temp->next = new_node;
		new_node->prev = temp;
		return;
	}
}


void push(int _data)   // 맨 마지막 노드가 top될거 // addToDLL이랑 같음
{
	addToDLL(_data);    //full 검사 안해도 됨;
	return;
}

int pop()
{
	// 예외처리 : 
	// 비어있는경우 - 그냥 리턴
	// 헤드하나뿐인경우  - 헤드 0처리 해주고 값은 pop하고
	// 여러가지인 경우 
	//

	struct DLL_node* temp = head;
	int res = 0;

	if (isStackEmpty())
	{
		return -999;
	}

	if (head->next == 0)  // 노드가 하나
	{
		int res = head->data;
		free(head);
		head = 0;

		return res;
	}

	while (temp->next != 0)
	{
		temp = temp->next;
	}

	res = temp->data;                    // res에 top값을 젖=저장 시킨 후 리턴을 한다는걸 먼저 만든 후 가운데 조건 만들기 
	temp->prev->next = 0;                // temp와 이 전 노드들의 연결 끊고 free(temp)
	free(temp);


	return res;


}

int main()
{
	push(5);
	push(3);
	push(1);
	push(40);   // 40넣으면 40부터 거꾸로 3개만 출력됨

	printf("%d \n", pop());
	printf("%d \n", pop());
	printf("%d \n", pop());      // 이거 푸쉬보다 많이쓰면 -999나와야 함


	return 0;
}


#endif          //이렇게 #if 0 과 #endif 써주면 전처리가 인돼서 창고처럼 쓸 수 있고 위의 숫자 0 이외로 바꾸면 전처리 가능

//struct DLL_node {
//	int data;
//	struct DLL_node* next;
//	struct DLL_node* prev;
//};
//
//struct DLL_node* head = 0;
//
//void addToDLL(int _data)
//{
//	struct DLL_node* temp = head;
//	struct DLL_node* new_node = (struct DLL_node*)malloc(sizeof(struct DLL_node));
//
//	new_node->data = _data;
//	new_node->next = new_node->prev = 0;
//
//	if (head == 0)
//	{
//		head = new_node;
//		return;
//	}
//
//	else
//	{
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		temp->next = new_node;
//		new_node->prev = temp;
//		return;
//	}
//}
//
//int isQueueEmpty()
//{
//	return (head == 0);
//}
//
//void enqueue(int _data)
//{
//	addToDLL(_data);
//	return;
//}
//
//int dequeue()
//{
//	int res = 0;
//
//
//	if (isQueueEmpty())
//	{
//		return -999;
//	}
//
//	// queue is only one
//	if (head->next == 0)
//	{
//		res = head->data;
//		free(head);
//		head = 0;
//		return res;
//
//	}
//
//
//	// queue's node in not only
//	res = head->data;
//	head = head->next; // head피신
//	free(head->prev); // 헤드 전 노드 프리
//	head->prev = 0; // 돼지꼬리 처리
//	return res;
//
//}
//
//int main()
//{
//	enqueue(5);
//	enqueue(3);
//	enqueue(1);
//	enqueue(40);
//
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//	printf("%d\n", dequeue());
//
//}