// chap.5 스택
// chap.6 큐

//stack 은
// 자기가 간 길에 나뭇가지등 길을 표시해서 거꾸로 찾아서 돌아가는 헨젤과 그레텔
// 이 나뭇가지 같은 도구가 스택이라고 한다 
// 맨 마지막에 한거를 맨 처음에 찾는 구조 
// 밑이 막힌 항아리 구조 LIFO(last in first out) 
// 아래처럼 진행되는 메인함수에서 a b c d 함수 진행시 d c b a순서로 진행되는 이런 거 
// 스택에 main->a->b->c->d 순서로 쌓이지만 해결되는건 d부터 역순으로 
// 함수의 호출관계 -> 스택
// 스택에 쓸 메모리가 부족해서 recursion(재귀)가 무한히는 불가능 하다.
//

//d() 
//{
//	return;
//}
//
//c()
//{
//	d()
//}
//
//b()
//{
//	c()
//}
//
//a() {
//	b()
//}
//
//main() {
//	a()
//}

//queue 는
// 밑이 뚫린 항아리 구조 FIFO(first in first out)
// network 장비에 사용됨
// 무선랜같은거에서 순차적으로 보낸 데이터가 순차적으로 처리된다.
// 큐도 메모리이기 떄문에 크기가 제한
// data 소실 현상이 일어남
//

//간단한 스택
// 1 2 3 순서로 넣어서 3 2 1 순서로 빼기 
// 배열 혹은 링크드 리스트
// 스택에 데이터를 넣는 행위를 push
// 빼는 행위는 pop
//

#include <stdio.h>
#include <stdlib.h>

#define STK_SIZE 5

int stack[STK_SIZE]; // 배열을 밑이 0 위가 4 인 서있는 배열로 생각하기 // 어디까지 쌓였는지가 중요
int top = -1;        // stack에 들어간 데이터의 마지막위치 배열이 하나면 초기값이 0이니까 pop은 -1로 해줌


// 스택이 꽉차있으면 1 아니먄 0
int isStackFull() 
{ 
	return (top == (STK_SIZE - 1));
}

// 스택비어있으면 1 아니면 0
int isStackEmpty()
{
	return (top == -1);
}

void push(int _data)
{
	// 모든 코딩에서 오류처리가 제일 먼저
	// 1. stack이 꽉 차있다.
	if (isStackFull())          // if문 안에 (isStackFull()==1) 이어도 여기서는 돌아가지만 다른데서는 안돌아 갈 수 있다.
		                        // 왜냐하면 c언어는 0은 거짓 0이 아닌 모든 수가 참이기 때문에 1이 아닌수가 혹시 돌아올 수 있다.
		                        // 그니까 저렇게 써 그냥
	{
		return;
	}

	top++;                          // 마지막 위치니까 하나 늘림
	stack[top] = _data;


}

int pop()
{
	int ret = 0;

	// 예외 비어있으면 -999
	if (isStackEmpty)
	{
		return -999;
	}

	ret = stack[top];  // 1. 짜는건 1번처럼 하는게 좋음 가독성이 정말 좋음
	top--;
	return ret;

	/*top--;             // 2.
	return stack[top];*/

	//return stack[top--]; //후위연산자 가능은 한데 별로 안좋고 위험 비추

}


int main()
{
	push(5);
	push(3);
	push(1);

	printf("%d ", pop());
	printf("%d ", pop());
	printf("%d ", pop());


	return 0;
}

// p.187 
//연결리스트로 구현한 스택 
// 스택을 배열로 하니까 조금 약점이 있음
// 그래서 sll dll로 스택을 구연하면 데이터 수의 유연성이 생김
//





// chap.6 queue
// FIFO
//

// array로 구현 

// 어디까지 들어왔는지 확인하는 변수        // rear
// 누구부터 나가는지 확인하는 변수          // front    이 두 변수명은 외우기
// 줄 서는것도 맨 뒤에서부터 하니까 rear로 들어와서 front로 나간다 생각하기

// 배열은 원래대로 누운상태로 생각 

// 처음 f와 r은 맨 앞
// r은 들어오는 애 따락서 옮김 -> enque
// 1부터 나가면 f는 뒤로 하나씩 옮김 -> deque

// 생각하기는 일직선으로 생각하지만 
// 실제로는 다 차고 앞이 비었으면 그 공간에 새로 값을 만들기 때문에
// 원형으로 만들어진다
// cicular queue  
// 배열로 구현하기 때문에 원형 
// 링크드 리스트로 하면 원형 필요 ㄴㄴ
// 
// f=r 이면 빈 큐
// 
// 서큘러 큐가 꽉 찬 상황의 조건은 어떻게 하느냐?
// 서큘러 여서 t=r이어도 꽉찬큐가 된다 
// 
// f=r을 그대로 쓰면 큐가 비었는지 꽉 찼는지 구분 불가능 
// 
// 그래서 나온 방법
// 1. 새론운 변수하나  full_flag 
// 근데 변수만들기 귀찮네,,,,,
// 
// 그래서 생각을 했지 
// 큐에서 한 공간을 버려서 
// 5칸 큐에 4칸만 차면 full인 상태로 하자 5번째 칸을 가트키는 r
// 차피 새로 변수를 만드나 하나 남기나 효율성은 비슷함 
// 
// 그래서 큐는 5공간을 만들면 4개만 쓸 수 있음 
// 
// 그래서 full은 어떻게 확인하나 
// r다음이 f 다
// 서큘러이기 때문에 
//

#include <stdio.h>
#include <stdlib.h>

#define QUE_SZ 5

int my_queue[QUE_SZ];

int front = 0;
int rear = 0;

int isQEmpty()
{
	return (front == rear);
}

int isQFull()
{
	return (((rear + 1) % QUE_SZ) == front);  // 5 % 5는 0이니까 맨 앞으로 보낼 수 있음 // 서큘러로 만드는 방법
}

void enqueue(int _data)
{
	if (isQFull())
	{
		return;
	}
	
	my_queue[rear] = _data;
	rear = (rear + 1) % QUE_SZ;
	return;
}

int dequeue()
{
	int ret = 0;

	if (isQEmpty())
	{
		return -999;
	}

	ret = my_queue[front];
	front = (front + 1) % QUE_SZ;
	return ret;

}

int main()
{
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);      //얘는 날아가야됨

	printf("%d", dequeue());
	printf("%d", dequeue());
	printf("%d", dequeue());
	printf("%d", dequeue());
	printf("%d", dequeue());


}


// 중요 !
// stack -- LIFO ,top , push, pop
// queue -- FIFO , front , rear , enqueue , dequeue


// 다음주 sll dll
// inert del 둘중에 하나씩 두개 
// 스택 큐 나옴