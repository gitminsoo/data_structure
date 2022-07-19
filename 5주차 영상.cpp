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

// 스택의 응용

// 수식계산

// 8 * 3 + 2 : 중위수식 (operater가 가운데 낀거)

// 후위수식 : 8 + 3 => 8 3 + 
// 장점) 중위수식은 연산자 우선순위를 알아야 함 
// 8 + 2 * 3 => 8 2 3 * +  
// 오퍼레이터가 나오면 앞의 두개를 그 연산자로 연산 
// 위의것은 2 3을 먼저 * 연산 후 8과 + 연산
// (8 + 2) * 3
// 8 2 + 3 *
// 
// 이걸 스택으로??
// 8 2 * 3 - = 13
// 왼에서 오로 진행하며 숫자가 나오면 스택에 푸시
// 연산자가 나오면 팝을 두번해서 그 연산자로 연산 
// 그 나온값을 다시 푸시 
// 다음 숫자 푸시 연산자 나오면 반복
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
//	char str[] = "82*3-";  // 두자릿 수도 해보기
//	int idx = 0;
//
//	while (str[idx] != '\0')
//	{
//		//숫자이면 push
//		if (str[idx] >= '0' && str[idx] <= '9')
//		{
//			// 숫자는 그 숫자의 아스키코드에서 '0'의 아스키 코드 값을 빼면 나온다 // 이해가능
//			push((int)str[idx] - '0');
//		}
//		else  // 숫자가 아니다 , 즉 연산자이다
//		{
//			int b = pop();        // 마이너스에서 나중에 팝된 값에서 지금 팝된값을 마이너스 해야해서 먼저 팝된값을b에 저장
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
//				printf("연산자 아닌거 같은디....\n");
//				return 0;
//			}
//		}
//
//		//operator면 2개 팝해서 계산하고 그 값을 다시 푸시
//		
//
//		idx++;
//	}
//	printf("결과는 : %d\n", pop());
//
//	return 0;
//}

// 후위수식으로 바꾸는거는 스택에 기호를 넣음
// 후위수식 계산은 스택에 숫자를 넣는거와 반대

int main()
{
	// 좌측에서 우로 읽어가면서	
	// 여는괄호는 stack push
	// 숫자 화면애 출력 stack에 안넣음
	// 닫는 괄호일경우 여는 괄호가 나올때까지 pop하면서 pop결과를 출력
	// * / 경우에는 무조건 push  ( * / 보다 우선순위가 높음)
	// + -  경우에는 , stack top에 있는것이 *or/ 면 pop해서 *,/를 출력, push(+,-)

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