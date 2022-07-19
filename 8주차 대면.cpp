//
// 시험에서는 특정 인덱스(숫자)가 움직인 횟수를 출력하게 넬거임
// 
// 9장 정렬
// selection insertion bubble shell merge quick heap radix
// 선택,삽입,거품,셸,합병,퀵,힙,기수 정렬
// 
// 힙은 이미함 맥스힙 --> 미니힙 으로 함
// 
// 위의 네개 -> 못난이 사총사 직관적 근데 성능은 안좋아
// 그 밑에 세개는 명품 정렬계의 샤넬
// 기수정렬은 특수 케이스
// 
// 정렬할게 5개 오름차순, 다 다른 값들, int만 생각
// 
// 선택정렬
// 키순정렬과 같음 -> 선택해서 정렬 너가 크네? 그다음은 너네
// 모든거랑 비교해서 제일 작을거를 앞에 세운다
// 나머지 4에 대해서도 똑같이 한다.
//

//
// 선택정렬의 타임 컴플렉시티
// big-o notation
// 등차수열의 합 n(n+1)/2 --> big-o 는 O(n^2)
// --> 못난이 사형제인 이유는 이 타임 컴플렉스드가 커서
// 타임컴플렉시티 --> 빅오
// 저거면 100개면 10000번은 움직여야됨
// 
// 삽입정렬 
// 등차수열 -> n(n-1)/2
// --> O(n^2)
// 
// 버블정렬
// n+n-1....+1
// O(n^2)
// 
// 그래서 얘네를 잡 정렬로 부르기도 함
// 
// 타임 컴플렉스티는 최악의 상황에 대해 걸린 시간
// 그래서 정렬 기본향에 따라 실제 구동시간은 다 달라짐 
// 
// **** 선택,삽입,버블은 O(n^2)
// 
// 정렬계의 샤넬은  
// O(n logn)
//  
//

//#include <stdio.h>
//
//// 못난이 소트는 이렇게 nested for문으로 생김
//void doselectionsort(int _data[], int _sz)
//{
//	int k = 0;  // 가장 작은애를 찾으면 데려올 위치
//	int temp = 0;
//	int i;
//	int least = 0; //제일 작은값을 갖는 index
//
//	for (k = 0; k < _sz - 1; k++) // 빝에거 반복만 하면 됨 // 맨 마지막위치는 for loop 안해도됨
//	{
//		least = k; // k가 가장 작다고 생각
//		
//		for (i = k + 1; i < _sz; i++) // 0번 부터 시작이고 그 뒤부터 비교니까 1부터 시작
//		{
//			if (_data[least] > _data[i]) // 리스트보다 더 작은 애가 나오면 그 위치를 기억
//			{
//				least = i;
//			}
//		}
//		// least에 가장 작은애의 인덱스가 들어있음
//		// 위치를 바꿔준다.
//
//		temp = _data[least];
//		_data[least] = _data[k];
//		_data[k] = temp;
//	}
//}
//
//void show_data(int _data[], int _sz)
//{
//	for (int i = 0; i < _sz; i++)
//	{
//		printf("%d ", _data[i]);
//	}
//	return;
//}
//
//int main()
//{
//	int data[] = { 45,76,87,20,1 };
//
//	// 차지한 전체크기 20바이트 나누기 각 요소의 크기 4 를 하면 5
//	int sz = sizeof(data) / sizeof(data[0]);
//	doselectionsort(data, sz);
//
//	show_data(data, sz);
//}

// 
// insertion sort
// 키에 맞춰서 앞사람 뒷사람과 알아서 바꾸는듯한 방법
// 5개가 있으면 맨 앞은 제외 2번재부터 실행
// 자리를 잠깐 옮겨서 자기 앞사람이 나보다 크면 
// 그 자리에 걔를 넣고
// 내가 그 앞자리로 감
// 
// 즉 맨 뒤에 애는 앞의 모두와 비교
// 
// 9 8 7 6 1
// 8 9 7 6 1
// 7 8 9 6 1
// 6 7 8 9 1
// 1 6 7 8 9
//

//#include <stdio.h>
//
//// 못난이 소트는 이렇게 nested for문으로 생김
//void doselectionsort(int _data[], int _sz)
//{
//	int k = 0;  // 가장 작은애를 찾으면 데려올 위치
//	int temp = 0;
//	int i;
//	int least = 0; //제일 작은값을 갖는 index
//
//	for (k = 0; k < _sz - 1; k++) // 빝에거 반복만 하면 됨 // 맨 마지막위치는 for loop 안해도됨
//	{
//		least = k; // k가 가장 작다고 생각
//		
//		for (i = k + 1; i < _sz; i++) // 0번 부터 시작이고 그 뒤부터 비교니까 1부터 시작
//		{
//			if (_data[least] > _data[i]) // 리스트보다 더 작은 애가 나오면 그 위치를 기억
//			{
//				least = i;
//			}
//		}
//		// least에 가장 작은애의 인덱스가 들어있음
//		// 위치를 바꿔준다.
//
//		temp = _data[least];
//		_data[least] = _data[k];
//		_data[k] = temp;
//	}
//}
//
//void show_data(int _data[], int _sz)
//{
//	for (int i = 0; i < _sz; i++)
//	{
//		printf("%d ", _data[i]);
//	}
//	return;
//}
//
//void do_insertion_sort(int _data[], int _sz)
//{
//	int i, j, temp;
//
//	for (i = 1; i < _sz; i++) // 반복
//	{
//		int me = _data[i]; // 자리비켜줌
//		for (j = i - 1; j >= 0; j--) // 내 앞에 있는애들 비교 
//		{
//			if (_data[j] > me)
//			{
//				_data[j + 1] = _data[j]; // j가 옮겨지니까 그걸 위해서 j+1로 해놓음
//			}
//			if (_data[j] < me) // 더이상 갈 수 없는 조건
//			{
//				break;
//			}
//		}
//		// 여기까지오면
//		_data[j + 1] = me;
//
//	}
//}
//
//int main()
//{
//	int data[] = { 45,76,87,20,1 };
//
//	// 차지한 전체크기 20바이트 나누기 각 요소의 크기 4 를 하면 5
//	int sz = sizeof(data) / sizeof(data[0]);
//	//doselectionsort(data, sz);
//	do_insertion_sort(data, sz);
//
//
//	show_data(data, sz);
//}

//
// bubble sort
// 거품은 위로 떠오른다
// 어레이가 있으면 그 숫자가 클수록 공기가 많다고 생각
// 어레이를 세로 방향으로 생각
// 큰애가 위로 이동
// selection sort의 정반대
// 
// 왼쪽이 바닥 
// 오른쪽이 top
// 3 2 1 8 4
// - 2 3 1 8 4
// - 2 1 3 8 4
// 바꿀 필요 없으니 유지 근데 8은 이동
// 2 1 3 4 8
// 
//

#include <stdio.h>

// 못난이 소트는 이렇게 nested for문으로 생김
void doselectionsort(int _data[], int _sz)
{
	int k = 0;  // 가장 작은애를 찾으면 데려올 위치
	int temp = 0;
	int i;
	int least = 0; //제일 작은값을 갖는 index

	for (k = 0; k < _sz - 1; k++) // 빝에거 반복만 하면 됨 // 맨 마지막위치는 for loop 안해도됨
	{
		least = k; // k가 가장 작다고 생각
		
		for (i = k + 1; i < _sz; i++) // 0번 부터 시작이고 그 뒤부터 비교니까 1부터 시작
		{
			if (_data[least] > _data[i]) // 리스트보다 더 작은 애가 나오면 그 위치를 기억
			{
				least = i;
			}
		}
		// least에 가장 작은애의 인덱스가 들어있음
		// 위치를 바꿔준다.

		temp = _data[least];
		_data[least] = _data[k];
		_data[k] = temp;
	}
}

void show_data(int _data[], int _sz)
{
	for (int i = 0; i < _sz; i++)
	{
		printf("%d ", _data[i]);
	}
	return;
}

void do_insertion_sort(int _data[], int _sz)
{
	int i, j, temp;

	for (i = 1; i < _sz; i++) // 반복
	{
		int me = _data[i]; // 자리비켜줌
		for (j = i - 1; j >= 0; j--) // 내 앞에 있는애들 비교 
		{
			if (_data[j] > me)
			{
				_data[j + 1] = _data[j]; // j가 옮겨지니까 그걸 위해서 j+1로 해놓음
			}
			if (_data[j] < me) // 더이상 갈 수 없는 조건
			{
				break;
			}
		}
		// 여기까지오면
		_data[j + 1] = me;

	}
}

void do_double_sort(int _data[], int _sz)
{
	int i, j, temp;

	for (i = 0; i < _sz; i++)
	{
		for (j = 0; j < _sz - 1 - i; j++)  // 맨 끝에 나보다 위에가 없으니까 sz-1 
			                               // 그리고 위애거 하나씩 빼면서 하니까 - i --> 생각해보기
		{
			if (_data[j] > _data[j + 1]) // 앞방울이 뒷방울보다 크다
			{
				temp = _data[j];
				_data[j] = _data[j + 1];
				_data[j + 1] = temp;
			}
		}
	}

	
}

int main()
{
	int data[] = { 45,76,87,20,1 };

	// 차지한 전체크기 20바이트 나누기 각 요소의 크기 4 를 하면 5
	int sz = sizeof(data) / sizeof(data[0]);
	//doselectionsort(data, sz);
	//do_insertion_sort(data, sz);
	do_double_sort(data, sz);


	show_data(data, sz);
}