#include <stdio.h>
#include <stdlib.h>

void selection(int nums[], int sz)
{
	int i;
	for (i = 0; i < sz - 1; i++)
	{
		int least = i;
		for (int j = i + 1; j < sz; j++)
		{
			if (nums[least] > nums[j])
			{
				least = j;
			}
		}
		int temp = nums[least];
		nums[least] = nums[i];
		nums[i] = temp;
	}
}

void insertion(int nums[], int sz)
{
	int i, j;
	for (i = 1; i < sz; i++)
	{
		int me = nums[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (me > nums[j])
			{
				break;
			}
			else
			{
				nums[j + 1] = nums[j];
			}
		}
		nums[j + 1] = me;
	}
}

void bubble(int nums[], int sz)
{
	int i, j;
	for (i = 0; i < sz; i++)
	{
		for (j = 0; j < sz - i - 1; j++)
		{
			if (nums[j] > nums[j + 1])
			{
				int temp = nums[j];
				nums[j] = nums[j + 1];
				nums[j + 1] = temp;
			}
		}
	}
}

void shell(int nums[], int sz)
{
	int gap = 0;
	int i = 0;
	int k = 0;

	for (gap = sz / 2; gap > 0; gap = gap / 2)
	{
		for (i = 0; i < gap; i++)
		{
			for (k = i + gap; k < sz; k = k + gap)
			{
				int me = nums[k];
				int d = 0;
				for (d = k - gap; d >= 0 && nums[d] > me; d = d - gap)
				{
					nums[d + gap] = nums[d];
				}
				nums[d + gap] = me;
			}
		}
	}
}

void do_merge(int nums[], int tarray[], int start, int mid, int end)
{
	int lstart = start;
	int lend = mid;
	int rstart = mid + 1;
	int rend = end;
	int i = lstart;
	int j = rstart;
	int t = lstart;

	while (1)
	{
		if (i > lend && j > rend)
		{
			break;
		}
		else if (i > lend)
		{
			tarray[t] = nums[j];
			t++;
			j++;
		}
		else if (j > rend)
		{
			tarray[t] = nums[i];
			t++;
			i++;
		}
		else if (nums[i] > nums[j])
		{
			tarray[t] = nums[j];
			t++;
			j++;
		}
		else if (nums[i] < nums[j])
		{
			tarray[t] = nums[i];
			t++;
			i++;
		}

	}

	for (i = 0; i <= end; i++)
	{
		nums[i] = tarray[i];
	}

}

void merge(int nums[], int start, int end, int tarray[])
{
	if (start == end)
	{
		return;
	}
	merge(nums, start, (start + end) / 2, tarray);
	merge(nums, (start + end) / 2 + 1, end, tarray);

	do_merge(nums, tarray, start, (start + end) / 2, end);

}

void quick(int nums[], int start, int end)
{
	if (start >= end)
	{
		return;
	}
	int pivot = start;
	int low = start + 1;
	int high = end;

	while (low <= high)
	{
		while (nums[low] <= nums[pivot] && low <= end)
		{
			low++;
		}
		while (nums[high] >= nums[pivot] && high >= start + 1)
		{
			high--;
		}
		if (low < high)
		{
			int temp = nums[low];
			nums[low] = nums[high];
			nums[high] = temp;
		}
	}

	int temp = nums[pivot];
	nums[pivot] = nums[high];
	nums[high] = temp;

	quick(nums, start, high - 1);
	quick(nums, high + 1, end);

}

int main()
{
	int nums[] = { 25,3,95,15,1,10,100,4,61 };
	int sz = sizeof(nums) / sizeof(nums[0]);

	int* tarray = (int*)malloc(sizeof(int) * sz);

	quick(nums, 0, sz - 1);

	for (int i = 0; i < sz; i++)
	{
		printf("%d ", nums[i]);
	}
}