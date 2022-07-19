// 무섭다..... 니가 선택한 자료구조다 악깡버해라
// 오늘 할거는 해부학임

// 리스트에대한 내용임

// list 
//들어오는 데이터를 담을 공간은 malloc으로 만듦 
//데이터를 받은 후 끈으로 연결해주는게 주요 포인트***
//어떻개?? 포인터를 이용해서 다음 데이터를 가르키게 한다.
//그럼 데이터 공간에는 실제 데이터와 포인터가 들어가야 한다 --> 구조체

// 탄생배경
//array의 무능함

//int a[10];
//단점 1 : 크기변환 불가능
//단점 2 : 배열의 중간이 나가면 뒤에거 하나하나를 앞으로 당겨줘야함(중간삭제가 매우 불편,비효율적)
//장점 1 : 빠르다 
//장점 2 : direct access가 가능 (a[n]으로 읽고 쓰기 가능)
//장점 3 : 안정적, 왜냐면 공간을 잡고 시작(malloc은 메모리가 부족하면 실패할 수 있음)  
//위 장점들(특히 3번) 때문에 임베디드 시스템은 array를 더 많이 씀

// mallc 쓰면 안되여??
//굳아이디어 -> 1번 단점 해결 
//그러나. 1번 문제를 해결하기위해 다른 malloc으로 이사를 가야함(비효율적)
//단점 2번은 안사라짐 

//list 데이터를 조각조각 나누어 합침
//데이터 들어올때마다 엮어준다는 느낌  --> array의 단점 1 단점 2 해결
// ㄹㅇ 굳 아이디어

//자기참조 구조체 만드는게 여기랑 이어지는 거임


#include <stdio.h>
#include <stdlib.h>

struct node {                           //list에서 데이터 저장은 node
	int data;
	struct node* next;                          // 데이터 상자 이렇게 만든거임 
};

// addToList
//입력데이터(_data)를 노드에 저장하고
//리스트에 붙인다

//리스트의 맨 앞 노드를 가르키는 포인터
//초기값 0은 비어있는 리스트라는 뜻 

struct node* head = 0;      // 꼭 전역변수로 // 프린트도 해야하니까

void addToList(int _data)           //_는 위의 data와 구분을 위해
{
	struct node* new_node = 0;

	// 1.노드 제작(_data를 담을)
	new_node = (struct node*)malloc(sizeof(struct node));     

	// 2.노드에 데이터 저장하고 포인터 초기화 
	new_node->data = _data;
	new_node->next = 0;    //아직 다음에 가르킬 애가 없다.
						   // 이미 있는 애의 뒤에 붙여야 하는데 맨 앞이 누구냐?
	                       // 이름은 head라고 하고 그걸 알면 그거의 포인터 +1,2,3... 으로 값을 알 수 있음

	// 3.기존 리스트에 추가
	//처음의 경우 리스트를 헤드로 만들어줌

	if (head == 0)             //리스트 집안의 첫째
	{
		head = new_node;      // 뉴노드가 헤드가 됨 둘다 포인터 형태라 가능
	}

	

	else
	{
		//1.리스트의 마지막 노드를 찾는다.
		struct node* temp = head;                    //헤드는 기준!!! 움직이면 안됨  그래서 임시 포인터를 만듦
		while (temp->next != 0)
		{
			temp = temp->next;     // temp 가 다음 노드를 가르키게한다. 마지막 노드가 되면 다음을 가르킬게 없다.
		}

		//2.마지막 노드(temp)의 next가 new_node를 가리키게 한다.
		temp->next = new_node;
		
	}

	
}

//List에 담긴 모든데이터를 보여주는 함수
//임시포인터를 만들어서 그 포인터로 값을 보여줘야함

void showList(void)
{
	struct node* temp = head;

	if (temp == 0)                 // 값이 없는 예외처리 필요
	{
		printf("\n리스트 비었어,,,, 정신차려!!!!!!!!\n");
	}

	else
	{
		while (temp != 0)         // 템프가 0이 아닌동안
		{
			printf("%d --> ", temp->data);   //값을 프린트
			temp = temp->next;             //템프가 다음거 가르키도록 
		}

		//템프가 마지막거 가르키면 끝남
	}
}

//malloc은 무조건 free를 해야하지만
//프로그램 끝나면 알아서 free되기 때문에 
//노드 지우게 되면 해야함

void clearList()
{
	struct node* temp = head;
	
	while (head != 0)
	{
		head = head->next;
		free(temp);
		temp = head;              // 구조체 포인터 크기로 이동하기만 하면 안되나?
	}
}

//1.삽입 (중간에 넣어버림)
//2.삭제 (필요한거만 지우기)  (검색--->해당노드 삭제)


//삭제하는거 먼저 
// 맨 앞 삭제 
// 중간삭제
// 맨 뒤 삭제        //마지막에서 전거를 돼지꼬리를 만들어 줘야함

//데이터를 가진 노드를 찾아소 
//그 노드의 주소를 반환
//반환 값이 구조체의 주소임, _data가 없으면 0반환

struct node* findFromList(int _data)
{
	struct node* temp = head;

	if (temp == 0)
	{
		return temp;              // temp 안에 0 들어 있으니까
	}
	else {

		while (temp != 0)
		{
			if (temp->data == _data)
			{
				return temp;      
			}
			else {
				temp = temp->next;
			}
		}
		return temp;       
	}
}

//me 를 가르키는 직전 노드
struct node* findPreNode(struct node* me)
{
	struct node* temp = head;

		if (temp->next == me)
		{
			//thankyou case
			return temp;
		}
		else
		{
			temp = temp->next;
		}
}

void delFromList(int _data)
{
	struct node* temp = findFromList(_data);

	if (temp == 0)    // 그 노드 없다.
	{
		// thankyou case
		printf("\n%s가 없어. 못지워.. 전신차려\n",_data);
		return;
	}

	// 1.맨 앞의 것
	if (temp == head)
	{
		head = head->next;
		free(temp);
		return;
	}


	// 2.중간거 // 지울것 앞의 주소가 중요함 (거기가 가르키는것을 지울거 다음걸로 만들어야 하니까)그래서 만들어야 함 

	else if (temp->next != 0)
	{
		struct node* prev = findPreNode(temp);
		prev->next = temp->next;
		free(temp);
		return;
	}

	else //3.마지막거
	{
		struct node* prev = findPreNode(temp);
		prev->next = 0;
		free(temp);
		return;
	}

}

//삽입

//중복 숫자는 없다. 가정
//where 노드찾아서 그 뒤에 what 노드 붙임
void insertIntoList(int _where, int _what)
{
	//1. _where 노드 찾기 
	struct node* temp = findFromList(_where);
	struct node* new_node = 0;

	//담은  노드가 없음 
	if (temp == 0)
	{
		// 할게 없음 ㄳ
		return; //휴강
	}

	//2. _what 노드 신규생성

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _what;
	new_node->next = 0;

	//3. _what 노드 추기
	new_node->next = temp->next;
	temp->next = new_node;

}

// 삽입 2 -> 앞에 넣기
// 맨 앞이면 head가 바뀌는 거니까 그거 생각 잘 하기

void insertbeforeIntoList(int _where, int _what)
{
	//1. _where 노드 찾기 
	struct node* temp = findFromList(_where);
	struct node* new_node = 0;

	//담은  노드가 없음 
	if (temp == 0)
	{
		// 할게 없음 ㄳ
		return; //휴강
	}

	//2. _what 노드 신규생성

	new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = _what;
	new_node->next = 0;
	
	// 3.where가 head인 경우
	if (temp == head)
	{
		new_node->next = head;
		head = new_node;
		return;
	}

	// haed가 아닌경우
	struct node* temp2 = 0;
	temp2 = findPreNode(temp);  // 목표 temp의 전 node를 temp2로 가르킴
	new_node->next = temp;
	temp2->next = new_node;
	return;

}



int main()
{
	addToList(10);
	addToList(20);
	addToList(30);

	showList();
	
	// 지우는 방법
	//맨뒤부터? 맨 마지막거 하나 지우고 찾는거는 힘듦
	//헤드에 임시 포인터를 만들고 헤드를 다음 노드로 옮긴다.
	//임시포인터를 다음 노드로 옮기고 다음 노드에 있던 헤드를 다다음 노드로 
	//반복-> 0이면 끝
	clearList();
	showList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);

	delFromList(20);
	showList();
	clearList();

	printf("\n_________________________\n");

	addToList(10);
	addToList(20);
	addToList(30);


	insertIntoList(20, 50);   //20뒤에 50 넣을 거임

	showList();
	clearList();

	printf("\n_________________________\n");
	addToList(10);
	addToList(20);
	addToList(30);


	insertbeforeIntoList(20, 50);   //20앞에 50 넣을 거임

	showList();
	clearList();

	 
}


// 코드 올려주시는거랑 비교해보자

//삽입은 영상으로

