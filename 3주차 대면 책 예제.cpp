// p.96 �޸� ���� �Ҵ��� ��

/* #include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main()
{
	int* p;

	p = (int*)malloc(SIZE * sizeof(int));


	if (p == NULL)           // �����Ҵ��� �ȵǸ�
	{
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.\n");    // �����ڵ� �����. //stderr�� ǥ�ؿ������,, ���۸� ���� â ����� 
		exit(1);            // Ż�⹮                                                        //fprintf������ ���� �ɵ�
	}

	for (int i = 0; i < SIZE; i++)
	{
		p[i] = i;
	}
	for (int i = 0; i < SIZE ; i++)
		printf("%d\n", p[i]);

	free(p);
	return 0;
} */

// p.97 �����޳븮 �Ҵ� ��
// studentTag�̸��� ����ü �ȿ� �̸� 10���迭 ���� gpa���� student �̸� ����
/* #include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

#pragma warning(disable:4996)


int main()
{
	typedef struct {
		char name[10];
		int age;
		int gpa;
	}STUDENT;

	STUDENT* s;
	

	s = (STUDENT*)malloc(sizeof(STUDENT));

	strcpy_s(s->name, "Park");
	s->age = 20;  //�̰� (*s).age��� ���� ���� 

	printf("%d\n", s->age);
	printf("%s\n", s->name);

	free(s);
	return 0;

}  */

/* #include <stdio.h>
#include <string.h>

#pragma warning(disable : 4996)

int main()
{
	struct person {
		char name[10];
		int age;
		float pay;
	};

	struct person a;

	scanf("%s",a.name);
	scanf("%d", &a.age);
	scanf("%f", &a.pay);

	printf("%s\n%d\n%f\n",a.name,a.age,a.pay);

	return 0;

}*/

/* #include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

int main() {
	typedef struct INFORMATION {
		float real;
		float imaginary;
	}complex;

	complex c1;
	complex c2;

	complex* p;
	p = (complex*)malloc(sizeof(complex));

	p->real = 20;
	p->imaginary = 15;

	printf("%f %f\n", p->real, p->imaginary);

	free(p);
	return 0;
}  */

//���� malloc ����

/* malloc->�����Ҵ�

�ý����� ����ǰ� �ִ� ���߿� �޸𸮸� ����� ��ɾ��̴�.

0 �������� 4 �������� 8 �������� ... 100 ��������
a �� �� �� ��
int main(void)
{

	int a = 5;

	int* p; �����Ҵ��� ������, ������ ������ �������ٰ� �Ҵ��ؾߵ�.
		�ֳ� ?
		malloc->���α׷��Ӱ� ������ ��ŭ�� ������ �ּҰ��� ��򰡿��ٰ� �������°ǵ�, malloc�� �ּҸ� ��ȯ��.
		--------------------------------
		int n;

	5

		scanf("%d", &n);

	int* p;
	p = (int*)malloc(sizeof(int) * n); -> 4 Byte * 5 = 20 Byte. int int 5����ŭ�� ����.

		int** p;

	p = (int**)malloc(sizeof(int*) * n);
	--->�� �ڵ�� ���� ���߹迭 ���鶧 ���ٸ�, �� �����ڵ��

		for (int i = 0; i < n; i++)
		{
			p[i] = (int*)malloc(sizeof(int) * 3);
		}

	�̷��� �ϸ�,

		p[n][3] �� �Ǵ°�.���� ?


		int 5���� ���� �� �ִ°���.p[5];
	------------------------------ -

		��->��->��->��->��->��->��->...->��



		int n[1000]

		free(p)
		return 0;
} */

//���� 2�� �迭 �����Ҵ� �ڵ� 

/*#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable:4996)

int main()
{

	int** arr;
	arr = (int**)malloc(sizeof(int*) * 2);
	for (int i = 0; i < 2; i++) {
		arr[i] = (int*)malloc(sizeof(int) * 3);
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}

	printf("%d %d %d %d %d %d", arr[0][0], arr[0][1], arr[0][2], arr[1][0], arr[1][1], arr[1][2]);

	for (int i = 0; i < 2; i++) {
		free(arr[i]);
	}

	free(arr);


	return 0;

}*/