// list : singly linked list, SLL
// 단점 : 어느 순서든 head부터 찾아서 한 방향으로 진행 
// 그래서 팔이 두개면 해결! (앞이랑 뒤를 서로 연결)
// 그래서 만들거지는 

// DLL : doubly linked list
// 장점 : 앞의 노드로 이동 가능
// 단점 1.메모리 소모 
//      2.구현 복잡

#include <stdio.h>
#include <stdlib.h>

struct DLL_node {                           //list에서 데이터 저장은 node
	int data;
	struct DLL_node* next;                          // 데이터 상자 이렇게 만든거임 
	struct DLL_node* prev;      // 앞의노드를 가르킴
};

// addToList
//입력데이터(_data)를 노드에 저장하고
//리스트에 붙인다

//리스트의 맨 앞 노드를 가르키는 포인터
//초기값 0은 비어있는 리스트라는 뜻 

struct DLL_node* head = 0;      // 꼭 전역변수로 // 프린트도 해야하니까

void showDLL(void)
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("\n놀라지마 아무것도 입력된게 없어... 노린거 맞지??\n");
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

	// 1.비어있는 DLL인가 

	if (head == 0)
	{
		head = new_node;
		return;
	}


	// 2.아니다... 맨끝에 추가

	while (temp->next != 0)
	{
		temp = temp->next;
	}

	temp->next = new_node;
	new_node->prev = temp;                 //sll과 다르게 추가해야 함
	return;

}

// 이전과 다르게 맨 뒤에서 앞으로 오면서 삭제하는 과정
// SLL처럼 민들어도 되지만 prev주소를 알 수 있으므로 이 방법으로 해보자

void clearDLL()
{
	struct DLL_node* temp = head;
	struct DLL_node* temp2 = 0;

	if (temp == 0)
	{
		printf("놀라지 마 아무것도 없어서 지울것도 없어\n");
		return;
	}

	// if(temp->next->next == 0) 이런 조건문을 주게되면 temp->next 가 주소를 갖지 않는다면
	// 오류가 발생하므로 아래와 같이 조건을 분리 해주어야 함

	// 맨 끝의 노드를 찾는다
	while (temp->next != 0)
	{
		temp = temp->next;
		//temp는 마지막 노드를 가르킨다
		//이제 거꾸로 올라오며 지우면 됨
	}

	while (temp != 0) {
		temp2 = temp->prev;
		free(temp);
		temp = temp2;
	}
	head = 0; //헤드는 예외처리 해줘야 함 // 아예 다 없애고 초기화 해주는거라 생각하기
}

// 1.데이터를 찾아서 삭제
//1. head
//2. 중간
//3. 끝
//1.데이터 있는 노드 탐색 2.그 노드 삭제

//_data가진 노드 찾으면 그 주소
// 못찾으면 0

struct DLL_node* findNode(int _data)
{
	struct DLL_node* temp = head;

	if (temp == 0)
	{
		printf("입력된 DLL이 없음\n");
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
		printf("%d 를 가진 노드가 없어용... 놀아용\n", _data);
		return;
	}

	// 맨 앞일 때
	if (temp == head)
	{
		//예외사항 : DLL이 head만 존재
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

	
	// 맨 마지막 노드인 경우
	if (temp->next == 0)
	{
		temp->prev->next = 0;
		free(temp);
		return;
	}

	//중간에 있을 때  // 조건분석 필요없음 예외처리는 위에서 다 함
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	free(temp);
	return;

}

//DLL삽입
// _where 을 찾아서 앞에 넣는다

void insertIntoBeforeDLL(int _where, int _what)
{
	struct DLL_node* temp = findNode(_where);
	struct DLL_node* new_node = 0;

	if (temp == 0)
	{
		printf("%d를 가진 노드가 없어요\n", _where);
		return;
	}

	new_node = (struct DLL_node*)malloc(sizeof(DLL_node));
	new_node->data = _what;
	new_node->prev = new_node->next = 0;
	
	//에외처리: 맨 앞일경우 앞에 붙이고 헤드로 바꾸기
	//1. temp가 head인 경우

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

//뒤에 넣는거 짜보기  (직접 짜보기)
// 직접 짜봤는데 이건 free안해도 되나?
void insertIntoAfterDLL(int _where, int _what)
{
	struct DLL_node* temp = findNode(_where);

	struct DLL_node* new_node = (DLL_node*)malloc(sizeof(DLL_node));
	new_node->data = _what;
	new_node->next = new_node->prev = 0;

	if (temp == 0)
	{
		printf("그 숫자는 없는데용??\n");
	}

	//예외는 맨 뒤에 넣을 때 
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



