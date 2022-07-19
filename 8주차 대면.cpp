//
// ���迡���� Ư�� �ε���(����)�� ������ Ƚ���� ����ϰ� �ڰ���
// 
// 9�� ����
// selection insertion bubble shell merge quick heap radix
// ����,����,��ǰ,��,�պ�,��,��,��� ����
// 
// ���� �̹��� �ƽ��� --> �̴��� ���� ��
// 
// ���� �װ� -> ������ ���ѻ� ������ �ٵ� ������ ������
// �� �ؿ� ������ ��ǰ ���İ��� ����
// ��������� Ư�� ���̽�
// 
// �����Ұ� 5�� ��������, �� �ٸ� ����, int�� ����
// 
// ��������
// Ű�����İ� ���� -> �����ؼ� ���� �ʰ� ũ��? �״����� �ʳ�
// ���Ŷ� ���ؼ� ���� �����Ÿ� �տ� �����
// ������ 4�� ���ؼ��� �Ȱ��� �Ѵ�.
//

//
// ���������� Ÿ�� ���÷���Ƽ
// big-o notation
// ���������� �� n(n+1)/2 --> big-o �� O(n^2)
// --> ������ �������� ������ �� Ÿ�� ���÷����尡 Ŀ��
// Ÿ�����÷���Ƽ --> ���
// ���Ÿ� 100���� 10000���� �������ߵ�
// 
// �������� 
// �������� -> n(n-1)/2
// --> O(n^2)
// 
// ��������
// n+n-1....+1
// O(n^2)
// 
// �׷��� ��׸� �� ���ķ� �θ��⵵ ��
// 
// Ÿ�� ���÷���Ƽ�� �־��� ��Ȳ�� ���� �ɸ� �ð�
// �׷��� ���� �⺻�⿡ ���� ���� �����ð��� �� �޶��� 
// 
// **** ����,����,������ O(n^2)
// 
// ���İ��� ������  
// O(n logn)
//  
//

//#include <stdio.h>
//
//// ������ ��Ʈ�� �̷��� nested for������ ����
//void doselectionsort(int _data[], int _sz)
//{
//	int k = 0;  // ���� �����ָ� ã���� ������ ��ġ
//	int temp = 0;
//	int i;
//	int least = 0; //���� �������� ���� index
//
//	for (k = 0; k < _sz - 1; k++) // ������ �ݺ��� �ϸ� �� // �� ��������ġ�� for loop ���ص���
//	{
//		least = k; // k�� ���� �۴ٰ� ����
//		
//		for (i = k + 1; i < _sz; i++) // 0�� ���� �����̰� �� �ں��� �񱳴ϱ� 1���� ����
//		{
//			if (_data[least] > _data[i]) // ����Ʈ���� �� ���� �ְ� ������ �� ��ġ�� ���
//			{
//				least = i;
//			}
//		}
//		// least�� ���� �������� �ε����� �������
//		// ��ġ�� �ٲ��ش�.
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
//	// ������ ��üũ�� 20����Ʈ ������ �� ����� ũ�� 4 �� �ϸ� 5
//	int sz = sizeof(data) / sizeof(data[0]);
//	doselectionsort(data, sz);
//
//	show_data(data, sz);
//}

// 
// insertion sort
// Ű�� ���缭 �ջ�� �޻���� �˾Ƽ� �ٲٴµ��� ���
// 5���� ������ �� ���� ���� 2������� ����
// �ڸ��� ��� �Űܼ� �ڱ� �ջ���� ������ ũ�� 
// �� �ڸ��� �¸� �ְ�
// ���� �� ���ڸ��� ��
// 
// �� �� �ڿ� �ִ� ���� ��ο� ��
// 
// 9 8 7 6 1
// 8 9 7 6 1
// 7 8 9 6 1
// 6 7 8 9 1
// 1 6 7 8 9
//

//#include <stdio.h>
//
//// ������ ��Ʈ�� �̷��� nested for������ ����
//void doselectionsort(int _data[], int _sz)
//{
//	int k = 0;  // ���� �����ָ� ã���� ������ ��ġ
//	int temp = 0;
//	int i;
//	int least = 0; //���� �������� ���� index
//
//	for (k = 0; k < _sz - 1; k++) // ������ �ݺ��� �ϸ� �� // �� ��������ġ�� for loop ���ص���
//	{
//		least = k; // k�� ���� �۴ٰ� ����
//		
//		for (i = k + 1; i < _sz; i++) // 0�� ���� �����̰� �� �ں��� �񱳴ϱ� 1���� ����
//		{
//			if (_data[least] > _data[i]) // ����Ʈ���� �� ���� �ְ� ������ �� ��ġ�� ���
//			{
//				least = i;
//			}
//		}
//		// least�� ���� �������� �ε����� �������
//		// ��ġ�� �ٲ��ش�.
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
//	for (i = 1; i < _sz; i++) // �ݺ�
//	{
//		int me = _data[i]; // �ڸ�������
//		for (j = i - 1; j >= 0; j--) // �� �տ� �ִ¾ֵ� �� 
//		{
//			if (_data[j] > me)
//			{
//				_data[j + 1] = _data[j]; // j�� �Ű����ϱ� �װ� ���ؼ� j+1�� �س���
//			}
//			if (_data[j] < me) // ���̻� �� �� ���� ����
//			{
//				break;
//			}
//		}
//		// �����������
//		_data[j + 1] = me;
//
//	}
//}
//
//int main()
//{
//	int data[] = { 45,76,87,20,1 };
//
//	// ������ ��üũ�� 20����Ʈ ������ �� ����� ũ�� 4 �� �ϸ� 5
//	int sz = sizeof(data) / sizeof(data[0]);
//	//doselectionsort(data, sz);
//	do_insertion_sort(data, sz);
//
//
//	show_data(data, sz);
//}

//
// bubble sort
// ��ǰ�� ���� ��������
// ��̰� ������ �� ���ڰ� Ŭ���� ���Ⱑ ���ٰ� ����
// ��̸� ���� �������� ����
// ū�ְ� ���� �̵�
// selection sort�� ���ݴ�
// 
// ������ �ٴ� 
// �������� top
// 3 2 1 8 4
// - 2 3 1 8 4
// - 2 1 3 8 4
// �ٲ� �ʿ� ������ ���� �ٵ� 8�� �̵�
// 2 1 3 4 8
// 
//

#include <stdio.h>

// ������ ��Ʈ�� �̷��� nested for������ ����
void doselectionsort(int _data[], int _sz)
{
	int k = 0;  // ���� �����ָ� ã���� ������ ��ġ
	int temp = 0;
	int i;
	int least = 0; //���� �������� ���� index

	for (k = 0; k < _sz - 1; k++) // ������ �ݺ��� �ϸ� �� // �� ��������ġ�� for loop ���ص���
	{
		least = k; // k�� ���� �۴ٰ� ����
		
		for (i = k + 1; i < _sz; i++) // 0�� ���� �����̰� �� �ں��� �񱳴ϱ� 1���� ����
		{
			if (_data[least] > _data[i]) // ����Ʈ���� �� ���� �ְ� ������ �� ��ġ�� ���
			{
				least = i;
			}
		}
		// least�� ���� �������� �ε����� �������
		// ��ġ�� �ٲ��ش�.

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

	for (i = 1; i < _sz; i++) // �ݺ�
	{
		int me = _data[i]; // �ڸ�������
		for (j = i - 1; j >= 0; j--) // �� �տ� �ִ¾ֵ� �� 
		{
			if (_data[j] > me)
			{
				_data[j + 1] = _data[j]; // j�� �Ű����ϱ� �װ� ���ؼ� j+1�� �س���
			}
			if (_data[j] < me) // ���̻� �� �� ���� ����
			{
				break;
			}
		}
		// �����������
		_data[j + 1] = me;

	}
}

void do_double_sort(int _data[], int _sz)
{
	int i, j, temp;

	for (i = 0; i < _sz; i++)
	{
		for (j = 0; j < _sz - 1 - i; j++)  // �� ���� ������ ������ �����ϱ� sz-1 
			                               // �׸��� ���ְ� �ϳ��� ���鼭 �ϴϱ� - i --> �����غ���
		{
			if (_data[j] > _data[j + 1]) // �չ���� �޹�ﺸ�� ũ��
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

	// ������ ��üũ�� 20����Ʈ ������ �� ����� ũ�� 4 �� �ϸ� 5
	int sz = sizeof(data) / sizeof(data[0]);
	//doselectionsort(data, sz);
	//do_insertion_sort(data, sz);
	do_double_sort(data, sz);


	show_data(data, sz);
}