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
////List�� ���� �� �ְ� ����Ʈ �ڽ��� �ø��� �Լ�
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
////List �� ��� ���� �����ִ� �Լ� 
//
//void showList(void)
//{
//	struct node* temp = head;
//
//	if (temp == 0)
//	{
//		printf("\n���� ����\n");
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
//// ���� ������� ������ ���ڸ� ���ִ� �Լ��� ���� ��
//// ������ �װ� ��� �ִ��� ã�� �� 
//// �� ������ �װ� ó������ �߰����� �� ���������� Ȯ���ؼ� 
//// �� ������ ����Ű�� next���� �� �������� �̾� ����� 
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
		printf("������ ��尡 �����ϴ�. �ٽ� Ȯ���� �ּ���\n");
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

void clearList()   //�ѹ� �� ����
{
	struct node* temp = 0;
	temp = head;

	if (temp == 0)
	{
		printf("���� ��尡 �����ϴ�.\n");
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
		printf("�� ���� �����\n");
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

void insertIntoList(int _where, int _what)   // �ڿ� �ִ� ��
{
	struct node* temp = findList(_where);

	if (temp == 0)
	{
		printf("�� ���ڴ� ���µ���?\n");
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
		printf("�� ���� �����..\n");
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


	insertIntoList(30, 50);   //20�ڿ� 50 ���� ����

	showList();
	clearList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);


	insertIntobeforeList(10, 50);   //20�տ� 50 ���� ����

	showList();
	clearList();

	return 0;
}


// �������
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

//�¶��� ���� sll ����

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

