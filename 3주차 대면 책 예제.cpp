// p.96 메모리 동적 할당의 예

/* #include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main()
{
	int* p;

	p = (int*)malloc(SIZE * sizeof(int));


	if (p == NULL)           // 동적할당이 안되면
	{
		fprintf(stderr, "메모리가 부족해서 할당할 수 없습니다.\n");    // 오류코드 만든다. //stderr가 표준오류출력,, 버퍼링 없이 창 띄워줌 
		exit(1);            // 탈출문                                                        //fprintf까지는 몰라도 될듯
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

// p.97 동적메노리 할당 예
// studentTag이름의 구조체 안에 이름 10개배열 나이 gpa만들어서 student 이름 설정
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
	s->age = 20;  //이게 (*s).age라는 말과 같음 

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

//동교 malloc 설명

/* malloc->동적할당

시스템이 실행되고 있는 도중에 메모리를 만드는 명령어이다.

0 ㅁㅁㅁㅁ 4 ㅁㅁㅁㅁ 8 ㅁㅁㅁㅁ ... 100 ㅁㅁㅁㅁ
a ㅁ ㅁ ㅁ ㅁ
int main(void)
{

	int a = 5;

	int* p; 동적할당을 쓰려면, 무조건 포인터 변수에다가 할당해야돼.
		왜냐 ?
		malloc->프로그래머가 선택한 만큼의 변수를 주소공간 어딘가에다가 만들어놓는건데, malloc은 주소를 반환해.
		--------------------------------
		int n;

	5

		scanf("%d", &n);

	int* p;
	p = (int*)malloc(sizeof(int) * n); -> 4 Byte * 5 = 20 Byte. int int 5개만큼의 공간.

		int** p;

	p = (int**)malloc(sizeof(int*) * n);
	--->이 코드는 이제 이중배열 만들때 쓴다면, 이 다음코드는

		for (int i = 0; i < n; i++)
		{
			p[i] = (int*)malloc(sizeof(int) * 3);
		}

	이렇게 하면,

		p[n][3] 이 되는거.ㅇㅋ ?


		int 5개를 넣을 수 있는거임.p[5];
	------------------------------ -

		ㅁ->ㅁ->ㅁ->ㅁ->ㅁ->ㅁ->ㅁ->...->ㅁ



		int n[1000]

		free(p)
		return 0;
} */

//동교 2중 배열 동적할당 코드 

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