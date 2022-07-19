// DLL

#include <stdio.h>
#include <stdlib.h>

struct DLL_node {
	int data;
	struct DLL_node* next;
	struct DLL_node* prev;

};

struct DLL_node* head = 0;


void addToDLL(int _data)
{
	struct DLL_node* new_node = 0;
	new_node = (struct DLL_node*)malloc(sizeof(DLL_node));

	new_node->data = _data;
	new_node->prev = new_node->next = 0;

	if (head == 0)
	{
		head = new_node;
		return;
	}
	else
	{
		struct DLL_node* temp = head;
		while (temp->next != 0)
		{
			temp = temp->next;
		}

		new_node->prev = temp;
		temp->next = new_node;
	}
}

void showDLL()
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("입력된 노드가 없습니다.\n");
		return;
	}

	else
	{
		while (temp != 0)
		{
			printf("%d ---> ", temp->data);
			temp = temp->next;
		}
		printf("\n");
		return;
	}

}

void clearDLL()
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("노드 비었는 디??\n");
		return;
	}

	else
	{
		while (head != 0)
		{
			struct DLL_node* temp2 = head;
			head = head->next;
			free(temp2);

		}
		return;
	}

}

struct DLL_node* findDLL(int _data)
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("입력된 노드가 없음\n");
	}

	while (temp != 0)             // temp->data==0 이면 0을 넣었을 때 오류가 생기니까 잘 생각 해
	{
		if (temp->data == _data)
		{
			return temp;
		}
		temp = temp->next;

	}
	return temp;

}

void delFromDLL(int _data)
{
	struct DLL_node* temp = findDLL(_data);

	if (temp == 0)
	{
		printf("입력된 깂이 없음\n");
		return;
	}

	else
	{
		if (temp == head)
		{
			head = head->next;
			free(temp);
			return;
		}
		else if (temp->next == 0)
		{
			temp->prev->next = 0;
			free(temp);
			return;
		}


		else
		{
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			free(temp);
			return;
		}
	}

}

void insertIntoBeforeDLL(int _where, int _what)
{
	struct DLL_node* temp = findDLL(_where);
	struct DLL_node* new_node = 0;
	new_node = (DLL_node*)malloc(sizeof(DLL_node));
	new_node->data = _what;
	new_node->prev = new_node->next = 0;

	if (temp == 0)
	{
		printf("입력깂이 없네용~\n");
	}

	else if (temp == head)
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		return;
	}

	else
	{
		new_node->next = temp;
		new_node->prev = temp->prev;

		temp->prev->next = new_node;
		temp->prev = new_node;
		return;
	}

}

void insertIntoAfterDLL(int _where, int _what)
{
	struct DLL_node* temp = findDLL(_where);
	struct DLL_node* temp2 = head;

	struct DLL_node* new_node = 0;
	new_node = (DLL_node*)malloc(sizeof(DLL_node));
	new_node->data = _what;

	new_node->prev = new_node->next = 0;

	if (temp == 0)
	{
		printf("엥 뭐친거임??\n");
		return;
	}
	else
	{
		while (temp2->next != 0)
		{
			temp2 = temp2->next;
		}

		if (temp == temp2)
		{
			new_node->prev = temp;
			new_node->next = 0;

			temp->next = new_node;
			return;
		}

		else
		{
			new_node->prev = temp;
			new_node->next = temp->next;

			temp->next->prev = new_node;
			temp->next = new_node;
			return;
		}
	}


}






int main()
{
	addToDLL(10);
	addToDLL(20);
	addToDLL(30);

	showDLL();

	//clearDLL();
	//showDLL();

	//delFromDLL(100);
	//showDLL();

	//insertIntoBeforeDLL(300, 50);
	//showDLL();

	insertIntoAfterDLL(10, 50);
	showDLL();

	//clearDLL();

	//showDLL();

	return 0;
}

//1129

//#include <stdio.h>
//#include <stdlib.h>
//
//#pragma warning(disable : 4996)
//
//struct dnode {
//	int data;
//	struct dnode* next;
//	struct dnode* prev;
//};
//
//struct dnode* head = 0;
//
//void adddnode(int _data)
//{
//	struct dnode* nnode = 0;
//	nnode = (struct dnode*)malloc(sizeof(struct dnode));
//	nnode->data = _data;
//	nnode->next = nnode->prev = 0;
//
//	struct dnode* temp = head;
//
//	if (temp == 0)
//	{
//		head = nnode;
//		return;
//	}
//	else
//	{
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//
//		temp->next = nnode;
//		nnode->prev = temp;
//		return;
//
//	}
//}
//
//void revershow()
//{
//	struct dnode* temp = head;
//
//	if (temp == 0)
//	{
//		return;
//	}
//
//	else
//	{
//		while (temp->next != 0)
//		{
//			temp = temp->next;
//		}
//		while (temp != head)
//		{
//			printf("%d ", temp->data);
//			temp = temp->prev;
//		}
//		printf("%d ", head->data);
//		return;
//	}
//}
//
//void insert(int _point, int _data)
//{
//	struct dnode* temp = head;
//	struct dnode* nnode = 0;
//	nnode = (struct dnode*)malloc(sizeof(struct dnode));
//	nnode->data = _data;
//	nnode->next = nnode->prev = 0;
//
//	if (temp == 0)
//	{
//		return;
//	}
//
//	else
//	{
//		while (temp != 0)
//		{
//			if (temp->next == 0)
//			{
//				if (temp->data == _point)
//				{
//					nnode->prev = temp;
//					temp->next = nnode;
//					return;
//				}
//			}
//			else
//			{
//				if (temp->data == _point)
//				{
//					nnode->next = temp->next;
//					nnode->prev = temp;
//
//					nnode->next->prev = nnode;
//					nnode->prev->next = nnode;
//
//					return;
//				}
//			}
//			temp = temp->next;
//		}
//
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
//
//		adddnode(data);
//
//	}
//
//	int point;
//	int ins;
//
//	scanf("%d %d", &point, &ins);
//
//	insert(point, ins);
//
//	revershow();
//
//}