// list : singly linked list, SLL
// ���� : ��� ������ head���� ã�Ƽ� �� �������� ���� 
// �׷��� ���� �ΰ��� �ذ�! (���̶� �ڸ� ���� ����)
// �׷��� ��������� 

// DLL : doubly linked list
// ���� : ���� ���� �̵� ����
// ���� 1.�޸� �Ҹ� 
//      2.���� ����

#include <stdio.h>
#include <stdlib.h>

struct DLL_node {                           //list���� ������ ������ node
	int data;
	struct DLL_node* next;                          // ������ ���� �̷��� ������� 
	struct DLL_node* prev;      // ���ǳ�带 ����Ŵ
};

// addToList
//�Էµ�����(_data)�� ��忡 �����ϰ�
//����Ʈ�� ���δ�

//����Ʈ�� �� �� ��带 ����Ű�� ������
//�ʱⰪ 0�� ����ִ� ����Ʈ��� �� 

struct DLL_node* head = 0;      // �� ���������� // ����Ʈ�� �ؾ��ϴϱ�

void showDLL(void)
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("\n������� �ƹ��͵� �ԷµȰ� ����... �븰�� ����??\n");
		return;
	}

	while (temp != 0)
	{
		printf("%d---> ", temp->data);
		temp = temp->next;

	}
	printf("\n");
}

void addToDLL(int _data)
{
	struct DLL_node* temp = head;
	struct DLL_node* new_node = (struct DLL_node*)malloc(sizeof(struct DLL_node));
	new_node->data = _data;
	new_node->next = 0;
	new_node->prev = 0;

	// 1.����ִ� DLL�ΰ� 

	if (head == 0)
	{
		head = new_node;
		return;
	}


	// 2.�ƴϴ�... �ǳ��� �߰�

	while (temp->next != 0)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;                 //sll�� �ٸ��� �߰��ؾ� ��
	return;

}

// ������ �ٸ��� �� �ڿ��� ������ ���鼭 �����ϴ� ����
// SLLó�� �ε� ������ prev�ּҸ� �� �� �����Ƿ� �� ������� �غ���

void clearDLL()
{
	struct DLL_node* temp = head;
	struct DLL_node* temp2 = 0;

	if (temp == 0)
	{
		printf("����� �� �ƹ��͵� ��� ����͵� ����\n");
		return;
	}

	// if(temp->next->next == 0) �̷� ���ǹ��� �ְԵǸ� temp->next �� �ּҸ� ���� �ʴ´ٸ�
	// ������ �߻��ϹǷ� �Ʒ��� ���� ������ �и� ���־�� ��

	// �� ���� ��带 ã�´�
	while (temp->next != 0)
	{
		temp = temp->next;
		//temp�� ������ ��带 ����Ų��
		//���� �Ųٷ� �ö���� ����� ��
	}

	while (temp != 0) {
		temp2 = temp->prev;
		free(temp);
		temp = temp2;
	}
	head = 0; //���� ����ó�� ����� �� // �ƿ� �� ���ְ� �ʱ�ȭ ���ִ°Ŷ� �����ϱ�
}

// 1.�����͸� ã�Ƽ� ����
//1. head
//2. �߰�
//3. ��
//1.������ �ִ� ��� Ž�� 2.�� ��� ����

//_data���� ��� ã���� �� �ּ�
// ��ã���� 0

struct DLL_node* findNode(int _data)
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("�Էµ� DLL�� ����\n");
	}

	while (temp != 0)
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
	struct DLL_node* temp = findNode(_data);

	if (temp == 0)
	{
		printf("%d �� ���� ��尡 �����... ��ƿ�\n", _data);
		return;
	}

	// �� ���� ��
	if (temp == head)
	{
		//���ܻ��� : DLL�� head�� ����
		if (temp->next == 0)
		{
			free(temp);
			head = 0;
			return;
		}
		head = head->next;
		free(temp);
		head->prev = 0;
		return;
	}

	
	// �� ������ ����� ���
	if (temp->next == 0)
	{
		temp->prev->next = 0;
		free(temp);
		return;
	}

	//�߰��� ���� ��  // ���Ǻм� �ʿ���� ����ó���� ������ �� ��
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return;

}

//DLL����
// _where �� ã�Ƽ� �տ� �ִ´�

void insertIntoBeforeDLL(int _where, int _what)
{
	struct DLL_node* temp = findNode(_where);
	struct DLL_node* new_node = 0;

	if (temp == 0)
	{
		printf("%d�� ���� ��尡 �����\n", _where);
		return;
	}

	new_node = (struct DLL_node*)malloc(sizeof(DLL_node));
	new_node->data = _what;
	new_node->prev = new_node->next = 0;
	
	//����ó��: �� ���ϰ�� �տ� ���̰� ���� �ٲٱ�
	//1. temp�� head�� ���

	if (temp == head)
	{
		new_node->next = head;
		head->prev = new_node;
		head = new_node;
		return;
	}

	new_node->next = temp;
	new_node->prev = temp->prev;

	temp->prev = new_node;
	new_node->prev->next = new_node;
	return;

}

//�ڿ� �ִ°� ¥����  (���� ¥����)
// ���� ¥�ôµ� �̰� free���ص� �ǳ�?
void insertIntoAfterDLL(int _where, int _what)
{
	struct DLL_node* temp = findNode(_where);

	struct DLL_node* new_node = (DLL_node*)malloc(sizeof(DLL_node));
	new_node->data = _what;
	new_node->next = new_node->prev = 0;

	if (temp == 0)
	{
		printf("�� ���ڴ� ���µ���??\n");
	}

	//���ܴ� �� �ڿ� ���� �� 
	if (temp->next == 0)
	{
		temp->next = new_node;
		new_node->prev = temp;
		return;
	}

	new_node->prev = temp;
	new_node->next = temp->next;

	new_node->next->prev = new_node;
	temp->next = new_node;
	return;
	
}


int main()
{
	addToDLL(10);
	addToDLL(20);
	addToDLL(30);

	showDLL();

	//delFromDLL(30);
	//insertIntoBeforeDLL(30, 50);
	insertIntoAfterDLL(30, 50);
	//clearDLL();

	showDLL();

	return 0;
}



