//#include <stdio.h>
//#include <stdlib.h>
//
//
//// node 
//struct node {
//	int data;
//	struct node* next;
//};
//
//// head
//struct node* head = 0;
//
////List에 값을 더 넣고 리스트 박스를 늘리는 함수
//
//void addToList(int _data)
//{
//	struct node* new_node = 0;
//
//	new_node = (struct node*)malloc(sizeof(struct node));
//	new_node->data = _data;
//	new_node->next = 0;
//
//	if (head == 0)
//	{
//		head = new_node;
//	}
//
//	else
//	{
//		struct node* temp = head;
//
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//
//		temp->next = new_node;
//	}
//
//}
//
////List 의 모든 값을 보여주는 함수 
//
//void showList(void)
//{
//	struct node* temp = head;
//
//	if (temp == 0)
//	{
//		printf("\n값이 없읍\n");
//	}
//
//	else
//	{
//		while (temp != 0)
//		{
//			printf("%d ====> ", temp->data);
//			temp = temp->next;
//		}
//	}
//}
//
////List clear
//
//void clearList()
//{
//	struct node* temp = head;
//
//	while (temp != 0)
//	{
//		head = head->next;
//		free(temp);
//		temp = head;
//
//	}
//}
//
//// 지금 만들것은 지정한 숫자를 없애는 함수를 만들 것
//// 시작은 그게 어디 있는지 찾는 것 
//// 그 다음은 그게 처음인지 중간인지 맨 마지막인지 확인해서 
//// 그 다음을 가르키는 next값을 그 다음으로 이어 줘야함 
//
//int main()
//{
//	addToList(10);
//	addToList(20);
//	addToList(30);
//
//	showList();
//
//	clearList();
//
//	showList();
//}

#include <stdio.h>
#include <stdlib.h>

// SLL -> addToList, showList, clearList, delFromList, insertIntoList, insertbeforeIntoList

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
	}

	else
	{
		struct node* temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}

		temp->next = new_node;
	}
}

void showList()
{
	struct node* temp = head;

	if (temp == 0)
	{
		printf("생성된 노드가 없습니다. 다시 확인해 주세요\n");
	}

	else
	{
		while (temp != 0)
		{
			printf("%d ---> ", temp->data);
			temp = temp->next;
		}
	}
	printf("\n");

}

void clearList()   //한번 더 보기
{
	struct node* temp = 0;
	temp = head;

	if (temp == 0)
	{
		printf("지울 노드가 없습니다.\n");
	}

	else
	{
		while (head != 0)
		{
			head = head->next;
			free(temp);
			temp = head;
		}
	}
}

struct node* findList(int _data)
{
	struct node* temp = head;

	if (temp == 0)
	{
		return temp;
	}

	while (temp != 0)
	{
		if (temp->data == _data)
		{
			return temp;
		}
		temp = temp->next;
	}
	return temp;        // temp=0

}

struct node* findPrenode(struct node* me)
{
	struct node* temp = head;

	while (temp->next != me)
	{
		temp = temp->next;
	}
	return temp;
}

void delFromList(int _data)
{
	struct node* temp = findList(_data);


	if (temp == 0)
	{
		printf("그 값은 없어용\n");
	}

	if (temp == head)
	{
		head = head->next;
		free(temp);
		return;
	}


	if (temp->next != 0)
	{
		struct node* temp2 = findPrenode(temp);
		temp2->next = temp->next;
		free(temp);
		return;
	}
	else
	{
		struct node* temp2 = findPrenode(temp);
		temp2->next = 0;
		free(temp);
	}



}

void insertIntoList(int _where, int _what)   // 뒤에 넣는 것
{
	struct node* temp = findList(_where);

	if (temp == 0)
	{
		printf("그 숫자는 없는데용?\n");
		return;
	}
	struct node* new_node = 0;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _what;
	new_node->next = 0;

	new_node->next = temp->next;
	temp->next = new_node;

}


void insertIntobeforeList(int _where, int _what)
{
	struct node* temp = findList(_where);
	struct node* new_node = 0;
	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _what;
	new_node->next = 0;

	if (temp == 0)
	{
		printf("그 값은 없어요..\n");
		return;
	}

	if (temp == head)
	{
		head = new_node;
		new_node->next = temp;
		return;
	}

	else
	{
		struct node* temp2 = findPrenode(temp);
		new_node->next = temp;
		temp2->next = new_node;
		return;
	}
}





int main()
{
	addToList(10);
	addToList(20);
	addToList(30);

	showList();

	clearList();
	showList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);

	delFromList(30);
	showList();
	clearList();

	printf("\n_________________________\n");

	addToList(10);
	addToList(20);
	addToList(30);


	insertIntoList(30, 50);   //20뒤에 50 넣을 거임

	showList();
	clearList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);


	insertIntobeforeList(10, 50);   //20앞에 50 넣을 거임

	showList();
	clearList();

	return 0;
}


// 역순출력
//#include <stdio.h>
//#include <Stdlib.h>
//
//struct node {
//	int data;
//	struct node* next;
//};
//
//struct node* head = 0;
//
//void addToList(int _data)
//{
//	struct node* new_node = 0;
//	new_node = (struct node*)malloc(sizeof(struct node));
//	new_node->data = _data;
//	new_node->next = 0;
//
//	if (head == 0)
//	{
//		head = new_node;
//		return;
//	}
//	else
//	{
//		struct node* temp = head;
//
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//
//		temp->next = new_node;
//		return;
//	}
//
//}
//
//void reversshow()
//{
//	struct node* temp = head;
//	struct node* temp2 = head;
//
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//
//	while (temp != head)
//	{
//		while (temp2->next != temp)
//		{
//			temp2 = temp2->next;
//		}
//		printf("%d ", temp->data);
//		temp = temp2;
//		temp2 = head;
//	}
//	printf("%d", head->data);
//	return;
//}
//
//
//int main()
//{
//	addToList(10);
//	addToList(20);
//	addToList(30);
//	addToList(40);
//	addToList(50);
//
//	reversshow();
//
//}

//온라인 저지 sll 문제

//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning (disable:4996)
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
//	struct node* nnode = 0;
//	nnode = (struct node*)malloc(sizeof(struct node));
//	nnode->data = _data;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//		return;
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
//
//}
//
//void showlist()
//{
//	struct node* temp = head;
//
//	if (temp == 0)
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
//void dellist(int _data)
//{
//	struct node* temp = 0;
//	struct node* temp_prev = head;
//
//	if (head == 0)
//	{
//		return;
//	}
//	if (head->data == _data)
//	{
//		temp = head;
//		head = head->next;
//		free(temp);
//		return;
//	}
//	else
//	{
//		while (temp_prev->next != 0)
//		{
//			if (temp_prev->next->data == _data)
//			{
//				temp = temp_prev->next;
//				temp_prev->next = temp->next;
//				free(temp);
//				return;
//
//			}
//			temp_prev = temp_prev->next;
//		}
//
//	}
//}
//
//void del_point(int _p)
//{
//	struct node* temp = 0;
//	int cnt = 0;
//	struct node* temp_prev = 0;
//
//	if (_p == 1)
//	{
//		temp = head;
//		head = head->next;
//		free(temp);
//		return;
//	}
//	else
//	{
//		temp = head;
//		while (temp != 0)
//		{
//			cnt = cnt + 1;
//			if (cnt == _p)
//			{
//				temp_prev->next = temp->next;
//				free(temp);
//				return;
//			}
//			temp_prev = temp;
//			temp = temp->next;
//		}
//		return;
//	}
//}
//
//int main()
//{
//	int n;
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		int data;
//		scanf("%d", &data);
//		addlist(data);
//	}
//	int del;
//	scanf("%d", &del);
//	del_point(del);
//	showlist();
//}

