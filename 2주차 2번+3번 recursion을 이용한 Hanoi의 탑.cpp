#include <stdio.h>

// Hanoi�� ž

int num_steps = 0; //�׸� �ű�� Ƚ��  //���� ������ ����;

/*
num�� ��� ���ø� �ű�°�
from ���κ��� (�����) 0,1,2
to ����� ,(������)      0,1,2
temp �߰� �۴��(������) 0,1,2
*/

void hanoi(int num, int from, int temp, int to)
{
	//1. Ż������... ���Ƿ� ���ƿ���  //�Ű��ִ� ���� �� ��ü
	if (num == 1)
	{
		printf("%d�۴�� ---> %d �۴�� �Űܿ�...\n", from, to);
		num_steps += 1;
		return;
	}


	//2. ���� ��Ʈ..
	//�ڳ��� ����� �ֱ�

	hanoi(num - 1, from, to, temp);  // �� ���ú��� �ϳ� ���� ž�� from���� �������� temp�� ������ �������� ���������� to��
	hanoi(1, from, temp, to);        // �� �ؿ� �ִ� �� ���ø� from���� to�� ������ �ʿ��ϸ� temp���Ķ� 
	hanoi(num - 1, temp, from, to);  // ���� temp������ �Űܵξ��� ���� �ֵ��� temp���� to�� ������. �ʿ��ϸ� from�� ���Ķ�
	return;
}

/*void becomeHuman(char* s)   // �������� �λ�ö��
{
	// 1.ŻǮ���� 
	if (s == "���ư� ���� �ӹ��� ���� ����")
	{
		return;
	}

	// 2. ���� 
	becomeHuman("�� ����");
	becomeHuman("������ ����");
	becomeHuman("���Ǹ� ��Ű��");

}*/


int main()
{
	 
	hanoi(5, 0, 1, 2);     //3���� ������ 0������ 1�������� 2������ ������
	printf("�� %dȸ �׸� �Ű���\n", num_steps);
	return 0;
}


//recursion ����� �� �ؾ������� �׸�ŭ ���ǿ��� ���� ��Ŷ�

