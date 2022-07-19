// priority queue
// 우선순위 큐 
// 피포(FIFO)
// 
// 큐인데 피포의 성질을 가지지 않는다.
// 들어가는 순서는 들어가도 나오는건 중요도에따라 나온다
// 중요도가 높은것부터 나온다고 할때
// 1 2 10 3 순서로 인큐 시 (중요도)
// 10 3 2 1 순서로 나오게 한다.
// ==> 네트워킹에 주로 사용
// 전투기 등이면 커맨드 왔다리 갔다리 하면
// 제일 중요한 커맨드를 먼저 실행시켜주는 실행에 대해 사용
// 기업의 네트워크망에 대해
// 기업의 화상회의 스트리밍이 중요해서 그거를 프라이어티 큐로 해서
// 먼저 처리해준다 (회사의 라우터 장비(소프트웨어적으로 넣음)를  통해)
// QOS 퀄리티 오브 서비스에 주요 사용
// 
// 
// 어케 구현?
// 큐를 배열로 구현?
// --> 어려워용
// --> 많이 움직여야해서
// 
// 리스트로 구현시 
// 중요도 높은걸 앞으로 구현 
// --> 문제점은 자기 위피를 찾기위해 리스트 수만큼 움직여야함
// --> 쉽지 않아
// 
// BST -> 검색에 사용
// 이거랑 비슷한 상태로 구현 
// 시간을 반으로 줄일 수 있다
// 
// 
// =====> Heap (우선순위 큐를 만들기 위해 만들어낸 데이터구조)
// ==> 힙 없이 만들 수는 있지만 더 효율적으로 만들기 위한 구조
// 
// 힙 ==> 바이너리 트리
//  
// 풀 바이너리트리
// ==> 가득참
// 
// 컴플리트 바이너리트리
// ==>비어있더라도 왼쪽이 다 차있는것
// 
// 
// 힙의 조건
// ==> 컴플리트 바이너리트리
// 
// 외 힙이냐??
// 모래시계 떨어디면 생기는 모습을 보면
// 산처럼 생기는데 이 모습을 힙이라고 함
// 힙이 모래더미 쌓아 놓은것처럼 생겨서
// 
// max heap , min heap
// 
// 맥스힙은 루트의 값이 제일 크다
// 모든 부모가 모든 자식보다 크면 맥스힙 
// 
// 제일 큰 수가 루트에 있다.
// 
// 미니힙은 부모가 자식보다 작다.
// 
// 맥스힙은 우선순위 큐를 만드는 가장 효율적인 구조
// 
// 꺼내는건 루트부터
// 
// 루트가 나가면 채워줘야함
// 
// 만드는 순서는 우선 heap모영을 만들어주고 maxheap의 순서로 만듦
// 
// 구현은 어떻게 할까
// BST는 노드로 했지?
// ==> 포인터 처리등으로 시간이 많이 걸려
// ==> 배열로 만들거야 ==> 할수만 있다면 뭐든 배열로 만드는게 제일 좋아
// 그래서 배열로 만들거야
// 
// heap_size : 현재 maxheap에 들어있는 데이터의 갯수
// 
// enqueue
// 
// dequeue
//

#include <stdio.h>


#define HP_LEN 10   // 10이니까 9개까지 가능

int my_heap[HP_LEN];
int heap_size = 0;

void enqueue(int _data)
{
	if (heap_size == (HP_LEN - 1))
	{
		printf("full\n");
		return;
	}

	// 일단 자리만들어주기
	heap_size++;
	my_heap[heap_size] = _data; // heap의 모양 잡아주기

	//자기자리 찾아가기
	int me = heap_size;
	int parent = me / 2;

	while (1)
	{
		if (me == 1) // 탈출조건 중 내가 중요도 1번으로 왔을떄
		{
			return;
		}

		// 부모보다 작으니 여기가 내자리
		if (my_heap[me] < my_heap[parent])
		{
			return;
		}

		else  //부모가 아니었다.
		{
			// 부모 사기꾼을 몰아내고 자리를 차지
		    int temp = my_heap[parent];
			my_heap[parent] = my_heap[me];
			my_heap[me] = temp;

			// 한자리 차지함
			me = parent;
			parent = me / 2;
		}
	}

 }

int findRepalcer(int _me)
{
	// 자식 중 큰 값을 가진 자식의 인덱스를 반환 
    // 만약 자식이 없으면 0을 반환

	int left_child = _me * 2;
	int right_child = left_child + 1;

	// 무자식
	if (left_child > heap_size) 
	{
		return 0;
	}

	// 홑자식
	if (right_child > heap_size)
	{
		return left_child;
	}
	//쌍자식
	if (my_heap[left_child] < my_heap[right_child])
	{
		return right_child;
	}

	else
	{
		return left_child;
	}
}

int dequeue()
{
	if (heap_size == 0)
	{
		printf("empty\n");
		return -999;
	}

	int res = my_heap[1]; //큐에서 꺼내는 값

	// max_heap 복구 해야지 ----------------

	// 1.모양복구 (끝에 있는걸 위로)

	my_heap[1] = my_heap[heap_size];
	heap_size--;
	// 차피 맨 끝에 지워진 값을 힙사이즈가 안가리키므로 신경 안써도 됨
	// 그래서 힙 사이즈가 중요함

	// 2.집안 전통 복구 (부모남이 제일 위다)

	int me = 1;

	while (1)
	{
		int replacer = findRepalcer(me);

		//자식이 없으므로 여기가 내자리.
		if (replacer == 0)
		{
			return res;
		}

		//내자식보다 크다
		if (my_heap[me] > my_heap[replacer])
		{
			return res;
		}

		//자리를 비켜준다
		else
		{
			// 어차피 나갈거만 바꿔주면 다음 dequeue때 또 실해하며 me가 바뀜
			// me를 바꿔줄 필요 없음
			int temp = my_heap[me];
			my_heap[me] = my_heap[replacer];
			my_heap[replacer] = temp;

			me = replacer;
		}

	}
	// 자식 중 큰 값을 가진 자식의 인덱스를 반환 
	// 만약 자식이 없으면 0을 반환
	


	//-----------------------------


}


int main()
{
	enqueue(1); 
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	enqueue(6);
	enqueue(7);

	

	for (int i = 0; i < 7; i++)
	{
		printf("%d\n", dequeue());
	}

	return 0;
}