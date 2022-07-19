//// shell sort
//// insertion sort�� ������
////
//// ������ �����̴°��� �����ϱ�����
//// 
//// �幮�幮 ���ø����Ѵ�
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
//// gap �Ҹ�ŭ�� insertion sort ����
//// 
//// gap�� �߿�
////
//
//#include <stdio.h>
//#include <stdlib.h>
//
//void shell_sort(int _data[], int _sz)
//{
//	// 1.gap : sz/2 -- > �ݾ����̸鼭 1�� �ɶ�����
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
//// ���ٱⰡ �������� �� -> mergre
//// 
//// �� ��ü���� �ϳ������� ������ 2���� �ϳ��� ���ļ� sort�Ѵ�
//// ����� ���ó�� �ذᰡ��
//// nlogn�� ����� ������.
//// �޸𸮰� �ι� �ʿ��ϴٴ� ��������
//// (����Ʈ�� �����̽� ����)
//// �ΰ��� ������ ��������� ����
//// 
//// #include <stdlib.h> �ʿ�
////
//
//void do_merge(int nums[], int tarray[], int start, int mid, int end)
//{
//	int lstart = start;
//	int lend = mid;
//	int rstart = mid + 1;
//	int rend = end;
//	int i = lstart; // ���������� ������ġ
//	int j = rstart; // ������ ������ ������ġ
//	int t = lstart;
//
//	while (1) {
//		if ((i > lend) && (j > rend))  // merge end
//		{
//			break;
//		}
//
//		if (j > rend) // ���������� ���ڰ� �������
//		{
//			tarray[t] = nums[i];
//			t++;
//			i++;
//		}
//		else if (i > lend) // ������ ������ ���ڰ� �������
//		{
//			tarray[t] = nums[j];
//			t++;
//			j++;
//		}
//		else // ���ʿ� ���ڰ� �������Ƿ� ���� ���ڸ� ã�Ƽ� �ִ´�
//		{
//			if (nums[i] > nums[j]) // �������� �۴�
//			{
//				tarray[t] = nums[j];
//				t++;
//				j++;
//			}
//			if (nums[i] < nums[j]) // ������ �۴�
//			{
//				tarray[t] = nums[i];
//				t++;
//				i++;
//			}
//		}
//
//	}
//
//	// tarray�� merge�� ����� �ִ�
//	// �̰��� ���� �迭�� �����ؼ� �־���Ѵ�.
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
//	// ���ʰ� �������� ���� �Ѵ�.
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
//	// gap�� �������� �ݺ��� �ݾ� ���̸鼭 1�� �ɶ�����
//
//	int gap = 0;
//	int i = 0;
//
//	int k = 0;
//
//	for (gap = sz / 2; gap > 0; gap = gap / 2)
//	{
//		// insertion ������ �׷쿡 ���� ����
//		// �Ƹ� �� ���� for���� ���� �ȵ��ٵ�
//		// gap��ŭ �׷����� ��� �ؾ��ϹǷ� �ϴ°���
//
//		for (i = 0; i < gap; i++) 
//		{
//			// insertion ����
//			// ���� ������ �� ������� ���������� ��� �ݺ�
//			for (k = i + gap; k < sz; k = k + gap)
//			{
//				int me = num[k]; // �ڸ��� ��� ������
//				int d = 0; // �񱳴�� gap��ŭ ���� �ִ¾�
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
	int i = lstart; // �� ������ ������ġ
	int j = rstart; // ���� ������ ������ġ
	int t = lstart;

	while (1)
	{
		if ((i > lend) && (j > rend)) // merge end
		{
			break;
		}

		if (j > rend) // ���������� ����
		{
			tarray[t] = nums[i];
			t++;
			i++;
		}
		else if (i > lend) // ���� ������ ����
		{
			tarray[t] = nums[j];
			t++;
			j++;
		}
		else // ���ʿ� ���ڰ� ���� �����Ƿ� ������ �ִ´�
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

	// tarray�� merge�� ��� �ִ�
	// �̰��� ���� �򿭿� �����ؼ� �־������
	// �߿�  tarrat�� ���� �迭�� �Ѱ������
	for (i = start; i <= end; i++)
	{
		nums[i] = tarray[i];
	}
}

void merge_sort(int nums[], int start, int end, int tarray[])
{
	// Ż������
	if (start == end)
	{
		return;
	}

	merge_sort(nums, start, (start + end) / 2, tarray); // left merge
	merge_sort(nums, (start + end) / 2 + 1, end, tarray); // right merge

	// ���� �������� ���� �Ѵ�
	do_merge(nums, tarray, start, (start + end) / 2, end);

}




int main()
{
	int nums[] = { 23,32,34,100,87,65,2,90,21,1,3 };
	int sz = sizeof(nums) / sizeof(nums[0]);

	// merge sort�� �����ϱ� ���� �ӽ� �����
	int* tarray = (int*)malloc(sizeof(int) * sz);

	printf("sz is %d\n", sz);

	printf("------------shell sort----------------\n");

	// nums: ���Ĵ�� �迭 
	// 0: ���� �ε���
	// 1: ���� �ε���
	// �ӽù迭 : extra space --> tarray


	merge_sort(nums,0,sz-1,tarray); 
	free(tarray); // �̷��� �������൵ �ǰ� �����൵ �Ǳ� ��

	for (int i = 0; i < sz; i++)
	{
		printf("%d\n", nums[i]);
	}
	return 0;
}