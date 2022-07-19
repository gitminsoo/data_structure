//// shell sort
//// insertion sort의 개선판
////
//// 찔끔찔끔 움직이는것을 개선하기위해
//// 
//// 드문드문 샘플링을한다
//// 
//// gap 4
//// 15 80 99 2 4 7 1 20
//// 4 80 99 2 15 7 1 20 
//// 4 7 99 2 15 80 1 2
//// 4 7 1 2 15 80 99 20
//// 4 7 1 2 15 80 99 20
//// 
//// gap 2
//// 1 7 4 2 15 80 99 20
//// 1 2 4 7 15 20 99 80
//// 
//// gap 1
//// 1 2 4 7 15 20 80 99
//// 
//// gap 텀만큼을 insertion sort 진행
//// 
//// gap이 중요
////
//
//#include <stdio.h>
//#include <stdlib.h>
//
//void shell_sort(int _data[], int _sz)
//{
//	// 1.gap : sz/2 -- > 반씩줄이면서 1이 될때까지
//
//	int gap = 0;
//	int i = 0;
//	int k = 0;
//
//	for (gap = _sz / 2; gap > 0; gap = gap / 2)
//	{
//		// insretion sort -> each group
//		for (i = 0; i < gap; i++)
//		{
//			for (k = i + gap; k < _sz; k = k + gap)
//			{
//				int me = _data[k];
//				int d = 0;
//				for (d = k - gap; d >= 0 && _data[d] > me; d = d - gap)
//				{
//					_data[d + gap] = _data[d];
//				}
//				_data[d + gap] = me;
//			}
//		}
//
//
//	}
//}
//
////
//// merge sort
//// 
//// 물줄기가 합쳐지는 것 -> mergre
//// 
//// 각 개체들을 하나씩으러 나누고 2개를 하나로 합쳐서 sort한다
//// 재귀의 방식처럼 해결가능
//// nlogn의 빅오를 가진다.
//// 메모리가 두배 필요하다는 단점있음
//// (엑스트라 스페이스 존재)
//// 두개가 합쳐져 만들어지는 공간
//// 
//// #include <stdlib.h> 필요
////
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart; // 왼쪽조각의 현재위치
//	int j = rstart; // 오른쪽 조각의 현재위치
//	int t = lstart;
//
//	while (1) {
//		if ((i > lend) && (j > rend))  // merge end
//		{
//			break;
//		}
//
//		if (j > rend) // 왼쪽조각에 숫자가 남은경우
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (i > lend) // 오른쪽 조각에 숫자가 남은경우
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else // 양쪽에 숫자가 남았으므로 작은 숫자를 찾아서 넣는다
//		{
//			if (nums[i] > nums[j]) // 오른쪽이 작다
//			{
//				tarray[t] = nums[j];
//				t++;
//				j++;
//			}
//			if (nums[i] < nums[j]) // 왼쪽이 작다
//			{
//				tarray[t] = nums[i];
//				t++;
//				i++;
//			}
//		}
//
//	}
//
//	// tarray에 merge된 결과가 있다
//	// 이것을 원래 배열에 복사해서 넣어야한다.
//	for (i = start; i <= end; i++)
//	{
//		nums[i] = tarray[i];
//	}
//
//
//}
//
//void merge_sort(int nums[], int start, int end, int tarray[])
//{
//	if (start == end)
//	{
//		return;
//	}
//
//	merge_sort(nums, start, (start + end) / 2 , tarray); // left merge
//	merge_sort(nums, (start + end) / 2 + 1, end, tarray);   // right merge
//
//	// 왼쪽과 오른쪽을 머지 한다.
//	do_merge(nums, tarray, start, (start + end) / 2, end);
//
//}
//
//
//
//int main()
//{
//	int data[] = { 23,32,34,100,87,65,2,90,21,1,3 };
//
//	int sz = sizeof(data) / sizeof(data[0]);
//	int* tarray = (int*)malloc(sizeof(int) * sz);
//
//	merge_sort(data, 0,sz-1,tarray);
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d\n", data[i]);
//	}
//
//	return 0;
//}

//#include <stdio.h>
//
//void shell_sort(int num[], int sz)
//{
//	// gap을 사이즈의 반부터 반씩 줄이면서 1이 될때까지
//
//	int gap = 0;
//	int i = 0;
//
//	int k = 0;
//
//	for (gap = sz / 2; gap > 0; gap = gap / 2)
//	{
//		// insertion 각각의 그룹에 대해 실행
//		// 아마 이 밑의 for문이 이해 안될텐데
//		// gap만큼 그룹으로 묶어서 해야하므로 하는거임
//
//		for (i = 0; i < gap; i++) 
//		{
//			// insertion 구현
//			// 다음 갭과의 비교 사이즈보다 작은동안은 계속 반복
//			for (k = i + gap; k < sz; k = k + gap)
//			{
//				int me = num[k]; // 자리를 잠시 비켜줌
//				int d = 0; // 비교대상 gap만큼 전에 있는애
//				for (d = k - gap; d >= 0 && num[d] > me; d = d - gap)
//				{
//					num[d + gap] = num[d];
//				}
//				num[d + gap] = me;
//			}
//
//		}
//	}
//}
//
//int main()
//{
//	int nums[] = { 23,32,34,100,87,65,2,90,21,1,3 };
//	int sz = sizeof(nums) / sizeof(nums[0]);
//
//	printf("sz is %d\n", sz);
//
//	printf("------------shell sort----------------\n");
//
//	shell_sort(nums, sz);
//
//	for (int i = 0; i < sz; i++)
//	{
//		printf("%d\n", nums[i]);
//	}
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

void do_merge(int nums[], int tarray[], int start, int mid, int end)
{
	int lstart = start;
	int lend = mid;
	int rstart = mid + 1;
	int rend = end;
	int i = lstart; // 왼 조각의 현재위치
	int j = rstart; // 오른 조각의 현재위치
	int t = lstart;

	while (1)
	{
		if ((i > lend) && (j > rend)) // merge end
		{
			break;
		}

		if (j > rend) // 왼쪽조각만 남음
		{
			tarray[t] = nums[i];
			t++;
			i++;
		}
		else if (i > lend) // 오른 조각만 남음
		{
			tarray[t] = nums[j];
			t++;
			j++;
		}
		else // 양쪽에 숫자가 남아 있으므로 작은걸 넣는다
		{
			if (nums[i] < nums[j])
			{
				tarray[t] = nums[i];
				t++;
				i++;
			}
			if (nums[i] > nums[j])
			{
				tarray[t] = nums[j];
				t++;
				j++;
			}
		}

	}

	// tarray에 merge된 결고가 있다
	// 이것을 원래 뱌열에 복사해서 넣어줘야함
	// 중요  tarrat를 원래 배열로 넘겨줘야함
	for (i = start; i <= end; i++)
	{
		nums[i] = tarray[i];
	}
}

void merge_sort(int nums[], int start, int end, int tarray[])
{
	// 탈출조건
	if (start == end)
	{
		return;
	}

	merge_sort(nums, start, (start + end) / 2, tarray); // left merge
	merge_sort(nums, (start + end) / 2 + 1, end, tarray); // right merge

	// 왼쪽 오른쪽을 머지 한다
	do_merge(nums, tarray, start, (start + end) / 2, end);

}




int main()
{
	int nums[] = { 23,32,34,100,87,65,2,90,21,1,3 };
	int sz = sizeof(nums) / sizeof(nums[0]);

	// merge sort를 구현하기 위한 임시 저장소
	int* tarray = (int*)malloc(sizeof(int) * sz);

	printf("sz is %d\n", sz);

	printf("------------shell sort----------------\n");

	// nums: 정렬대상 배열 
	// 0: 시작 인덱스
	// 1: 종료 인덱스
	// 임시배열 : extra space --> tarray


	merge_sort(nums,0,sz-1,tarray); 
	free(tarray); // 이렇게 프리해줘도 되고 안해줘도 되긴 함

	for (int i = 0; i < sz; i++)
	{
		printf("%d\n", nums[i]);
	}
	return 0;
}