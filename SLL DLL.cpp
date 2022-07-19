// sll

//#include <stdio.h>
//#include <stdlib.h>
//
//struct node {
//	int data;
//	node* next;
//};
//
//node* head = 0;
//
//void addList(int v)
//{
//	node* nnode = (node*)malloc(sizeof(node));
//	nnode->data = v;
//	nnode->next = 0;
//
//	if (head == 0)
//	{
//		head = nnode;
//		return;
//	}
//
//	node* temp = head;
//	while (temp->next != 0)
//	{
//		temp = temp->next;
//	}
//	temp->next = nnode;
//}
//
//void show()
//{
//	if (head == 0)
//	{
//		return;
//	}
//	node* temp = head;
//	while(temp != 0)
//	{
//		printf("%d ", temp->data);
//		temp = temp->next;
//	}
//}
//
//void insertList(int p, int v)
//{
//	if (head == 0)
//	{
//		return;
//	}
//
//	node* nnode = (node*)malloc(sizeof(node));
//	nnode->data = v;
//	nnode->next = 0;
//
//	node* temp = head;
//
//	while (temp != 0)
//	{
//		if (temp->data == p)
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
//void delList(int v)
//{
//	if (head == 0)
//	{
//		return;
//	}
//	node* temp = head;
//	node* temp_p = 0;
//
//	while (temp != 0)
//	{
//		if (temp->data == v)
//		{
//			if (temp==head)
//			{
//				if (head->next == 0)
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
//
//			if (temp->next == 0)
//			{
//				temp_p->next = 0;
//				free(temp);
//				return;
//			}
//
//			else
//			{
//				temp_p->next = temp->next;
//				free(temp);
//				temp = temp_p;
//				continue;
//			}
//
//		}
//		temp_p = temp;
//		temp = temp->next;
//	}
//	return;
//}
//
//void clear()
//{
//	if (head == 0)
//	{
//		return;
//	}
//	
//	node* temp = head;
//	while (head != 0)
//	{
//		head = head->next;
//		free(temp);
//		temp = head;
//	}
//}
//
//int main()
//{
//	addList(5);
//	addList(4);
//	addList(3);
//	addList(2);
//	addList(1);
//
//	insertList(5, 3);
//	insertList(1, 5);
//
//	delList(3);
//
//
//	show();
//}