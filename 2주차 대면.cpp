#include <stdio.h>

//�ΰ��� �� recursion  (�����̾��� ��)

//ù���� ������ ������ �´��ŷ� �Ұ���

//4*3=12

/* int mul(int m, int n)
{
	if (n == 0)
	{
		return 0;
	}

	return m + mul(m, n - 1);
}


int main()
{
	int m, n;
	scanf_s("%d %d", &m, &n);

	int mul1 = 0;

	mul1 = mul(m, n);

	printf("%d", mul1);

	return 0;
}  */

//__________________����____________________//

// 1.p.68 �迭
// ������ �ѹ��� ������ ���鶧
// 1���� �迭 
/* int a[10];

a[0]
a[1]
...
a[9]
*/

// p.70 2���� �迭 
// ���ڸ� ��, ���ڸ� ��

/* int a[3][4];
a[0][0]
....
a[2][3] */

// p.71 �� 3.1

// #include <stdio.h>

//call bt reference ---> ������ �Ѿ��.  
//why? ������ Ŀ���� 4����Ʈ~8����Ʈ �ε� �迭�� Ŭ���� ũ�Ⱑ Ŀ���� ���簡 �����ϴ� �ؼ� ������ ���
//�迭�� �μ��� �Ѱܼ� 
//�Լ������� ���� �ٲٸ� 
//original �迭���� �ٲ��.

//call by value ---> ���纻�� �ѱ��
//���� (�迭�� �ƴ�)�� �μ��� �Ѱܼ� 
//�Լ������� ���� �ٲ㵵 
//original���� ������ �ʴ´�

/* void foo(int v[])
{
	 v[1] = 10;
}

void bar(int k)
{
	k = 3000;
}
int main()
{
	int a[3] = { 1,2,3 };
	int b = 100;

	printf("%d\n",b);
	bar(b);
	printf("%d\n", b);

	printf("%d\n", a[1]);
	foo(a);
	printf("%d\n", a[1]);
} */

// 3.4 ����ü

//3���� �����ͱ����� �߿��Ѱ� �����ϴ°� ��

// �� ���������?
//---> ���ο� datatype�� ���� �� �ִ�.
//int char float... �̰Ŵ� ���Ѱ� 
// if ����� ���̿� �����Ը� �ϳ��� ������ ���� �� ������?

// 2-2�� ��ü��� sw  c++
// c==>c++
//struct(data) ==> class(data+function)

struct A {
	int age;
	int weight;
};

struct A person;
int       k;          //�̰Ŷ� ���� ���� 

person.age = 21;
person.weight = 70.4;  //�̷��� ���� ����

typedef struct A {
	int age;
	int weight;
} PERSON_INFO;  // �������� // ������ �빮�� 

struct A k;
PERSON_INFO k; // �ΰ� ���� ��


//p.84   ����ü ���԰� �񱳿��� 
PERSON_INFO a;
a.age = 20;
a.weight = 70.4;

PERSON_INFO b;
b = a;
b.age ? 20;
b.weight ? 70.4;   //������ ���� �ſ� ����

if(a==b)  // �̷��񱳴� �ȵ�

if(a.age==b.age && a.weight == b.weight)  // �̷��� ���ϱ� 

// p.85 �ڱ����� ����ü �� 5�� *****
//self-referencial structure

struct A {
	int age;
	int weight;
	struct A *k;  // �ڱ��ڽ��� ����Ų��. //struct A�� ���°Ŵ� �ȵ� �ּ� �־��ִ°� ���� //������ �ּҸ� �Ѱ��ִ°� 
};

// ����ä �迭 

struct A k[10];

// 3.5 ������ pointer
//�ڹٴ� �����͸� ���ְ��� ����Ŷ� �����Ͱ� ���� 
// c,c++--- >java ----> kotlin

// p.87 �������� ����
int a = 10;  //a�� ����� ���°� ��ǻ�ʹ� �ּҷ� ����. �츮�� �������� �̷� �ּҴ� �й� etc. �̷� �������� 

int* pa = &a;

//p.90 �迭�� ������ 
//�迭�� �̸��� �� �迭�� ����� �޸� �����ּ� // 160���̶� �ٸ��� �˾ƾ���
int a[10];
int* pa;
pa = a; 

//p.91 �������� ������ 

struct A {
	int age;
	float weight;
};

struct A a;
struct A* pa;  //�ּҸ� ���� ���� 
pa = &a;        //a�� �����ּ� ����

//pa�� �����ʹϱ� pa->age
//a�� ������ . ; a.age
pa->age = 20;           
pa->weight = 75.4;

// p.92 �Լ������� �о�� 

// p.92 �����Ϳ����� ���� 

int* a;   //����Ʈ �� ���� 907�� -> 908��
char* c;  //����Ʈ ȣ���� 907�� 101ȣ -> 102ȣ 

a = 100;
a += 1; // ==>104

c = 100;
c += 1; // ==>101

//p.93 �߰���

*p++
a = *p++;
//p�� ����Ű�� �������� ���� �����ͼ� a�� �ְ�  p�� ����Ű�� ���� ���� 1��ŭ ����
//===>
a = *p;
*p = *p + 1;    // �������ε� �̰� �� ����          // *�� �����ʿ� ������ ���� ���� ����  


*p--

(*p)++


// 3.6 �����޸��Ҵ� 
//<----> �����޸��Ҵ�

int a[10]; // ���� 

maloc // ���� 
//memory allocation

int* p;  // 4����Ʈ�� �پ�Ѱڴ�
p = (int*)malloc(40);  // 40����Ʈ �Ҵ�  //malloc�� Ȱ����� ���� �丮������ ���� ĳ���� ����
   // int ������ �ּ��� --> (int*)malloc(40)

char c;
c = (char*)malloc(100)

free(p); // �����޸� �� // malloc���ش�, ���� ������ �¾ƾ� �Ѵ�.
free(c);


#include <stdio.h>
#include <malloc.h> //malloc�ҰŸ� �� ��� ��ߵ�

/* int main()
{
	typedef struct A {
		int a;
		char c;
	}DATA_1;

	DATA_1 k;

	k.a = 1;
	k.c = 'a';

	printf("%d %c", k.a, k.c);



}  */

int main()
{
	typedef struct A {
		int cnt;
		int age;
	}P_INFO;

	P_INFO a;
	a.cnt = 1;
	a.age = 20;

	
	P_INFO k[10];

	P_INFO* p;
	p = &a;

	 p->age = 22;  // ī���ͷ� ���� �� ���� �־��ִ� �Ŵ� -> ���� �׳� �־��ٶ��� . ����.

	printf("%d\n", a.age);

	int* pa;
	pa = (int*) malloc(40);

} 
