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

int isStackEmpty()   // full �Լ��� ���� ����Ʈ�ϱ� �ȸ��� ��
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


void push(int _data)   // �� ������ ��尡 top�ɰ� // addToDLL�̶� ����
{
	addToDLL(_data);    //full �˻� ���ص� ��;
	return;
}

int pop()
{
	// ����ó�� : 
	// ����ִ°�� - �׳� ����
	// ����ϳ����ΰ��  - ��� 0ó�� ���ְ� ���� pop�ϰ�
	// ���������� ��� 
	//

	struct DLL_node* temp = head;
	int res = 0;

	if (isStackEmpty())
	{
		return -999;
	}

	if (head->next == 0)  // ��尡 �ϳ�
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

	res = temp->data;                    // res�� top���� ��=���� ��Ų �� ������ �Ѵٴ°� ���� ���� �� ��� ���� ����� 
	temp->prev->next = 0;                // temp�� �� �� ������ ���� ���� free(temp)
	free(temp);


	return res;


}

int main()
{
	push(5);
	push(3);
	push(1);
	push(40);   // 40������ 40���� �Ųٷ� 3���� ��µ�

	printf("%d \n", pop());
	printf("%d \n", pop());
	printf("%d \n", pop());      // �̰� Ǫ������ ���̾��� -999���;� ��


	return 0;
}

   
#endif          //�̷��� #if 0 �� #endif ���ָ� ��ó���� �εż� â��ó�� �� �� �ְ� ���� ���� 0 �ܷ̿� �ٲٸ� ��ó�� ����

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
//	head = head->next; // head�ǽ�
//	free(head->prev); // ��� �� ��� ����
//	head->prev = 0; // �������� ó��
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

// ������ ����

// ���İ��

// 8 * 3 + 2 : �������� (operater�� ��� ����)

// �������� : 8 + 3 => 8 3 + 
// ����) ���������� ������ �켱������ �˾ƾ� �� 
// 8 + 2 * 3 => 8 2 3 * +  
// ���۷����Ͱ� ������ ���� �ΰ��� �� �����ڷ� ���� 
// ���ǰ��� 2 3�� ���� * ���� �� 8�� + ����
// (8 + 2) * 3
// 8 2 + 3 *
// 
// �̰� ��������??
// 8 2 * 3 - = 13
// �޿��� ���� �����ϸ� ���ڰ� ������ ���ÿ� Ǫ��
// �����ڰ� ������ ���� �ι��ؼ� �� �����ڷ� ���� 
// �� ���°��� �ٽ� Ǫ�� 
// ���� ���� Ǫ�� ������ ������ �ݺ�
// 
//

#define STK_SZ 20

int my_stack[STK_SZ];
int top = -1;

void push(int _data)
{
	if (top == STK_SZ - 1)
	{
		return;
	}

	top++;
	my_stack[top] = _data;
	return;
}

int pop()
{
	int res = 0;
	if (top == -1)
	{
		return -999;
	}
	res = my_stack[top];
	top--;
	return res;
}


//int main()
//{
//	char str[] = "82*3-";  // ���ڸ� ���� �غ���
//	int idx = 0;
//
//	while (str[idx] != '\0')
//	{
//		//�����̸� push
//		if (str[idx] >= '0' && str[idx] <= '9')
//		{
//			// ���ڴ� �� ������ �ƽ�Ű�ڵ忡�� '0'�� �ƽ�Ű �ڵ� ���� ���� ���´� // ���ذ���
//			push((int)str[idx] - '0');
//		}
//		else  // ���ڰ� �ƴϴ� , �� �������̴�
//		{
//			int b = pop();        // ���̳ʽ����� ���߿� �˵� ������ ���� �˵Ȱ��� ���̳ʽ� �ؾ��ؼ� ���� �˵Ȱ���b�� ����
//			int a = pop();
//
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
//			default :
//				printf("������ �ƴѰ� ������....\n");
//				return 0;
//			}
//		}
//
//		//operator�� 2�� ���ؼ� ����ϰ� �� ���� �ٽ� Ǫ��
//		
//
//		idx++;
//	}
//	printf("����� : %d\n", pop());
//
//	return 0;
//}

// ������������ �ٲٴ°Ŵ� ���ÿ� ��ȣ�� ����
// �������� ����� ���ÿ� ���ڸ� �ִ°ſ� �ݴ�

int main()
{
	// �������� ��� �о�鼭	
	// ���°�ȣ�� stack push
	// ���� ȭ��� ��� stack�� �ȳ���
	// �ݴ� ��ȣ�ϰ�� ���� ��ȣ�� ���ö����� pop�ϸ鼭 pop����� ���
	// * / ��쿡�� ������ push  ( * / ���� �켱������ ����)
	// + -  ��쿡�� , stack top�� �ִ°��� *or/ �� pop�ؼ� *,/�� ���, push(+,-)

	char str[] = "(8-2)*3";
	int idx = 0;

	while (str[idx] != 0)
	{
		if (str[idx] == '(')
		{
			push(str[idx]);
		}
		else if (str[idx] > '0' && str[idx] <= '9')
		{
			printf("%c ", str[idx]);
		}
		else if (str[idx] == ')')
		{
			while (1)
			{
				char res = pop();
				if (res == '(')
				{
					break;
				}
				else
				{
					printf("%c ", res);
				}
			}
		}
		else if (str[idx] == '*' || str[idx] == '/')
		{
			push(str[idx]);
		}
		else
		{
			if (my_stack[top] == '*' || my_stack[top] == '/')
			{
				printf("%c ", pop());
				push(str[idx]);
			}
			else
			{
				push(str[idx]);
			}
		}
		idx++;
	}

	while (top != -1)
	{
		printf("%c", pop());
	}

	return 0;

}