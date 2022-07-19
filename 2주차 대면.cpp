#include <stdio.h>

//두개의 곱 recursion  (시험이었던 거)

//첫번재 문제는 무조건 냈던거로 할거임

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

//__________________수업____________________//

// 1.p.68 배열
// 변수를 한번에 여러개 만들때
// 1차원 배열 
/* int a[10];

a[0]
a[1]
...
a[9]
*/

// p.70 2차원 배열 
// 앞자리 행, 뒤자리 열

/* int a[3][4];
a[0][0]
....
a[2][3] */

// p.71 프 3.1

// #include <stdio.h>

//call bt reference ---> 원본이 넘어간다.  
//why? 변수는 커봐야 4바이트~8바이트 인데 배열은 클수록 크기가 커져서 복사가 위험하다 해서 원본을 사용
//배열을 인수로 넘겨서 
//함수내에서 값을 바꾸면 
//original 배열값도 바뀐다.

//call by value ---> 복사본을 넘긴다
//변수 (배열이 아닌)를 인수로 넘겨서 
//함수내에서 값을 바꿔도 
//original값은 변하지 않는다

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

// 3.4 구조체

//3장은 데이터구조에 중요한거 리뷰하는거 뿐

// 왜 만들었을까?
//---> 새로운 datatype을 만들 수 있다.
//int char float... 이거는 뻔한거 
// if 사람의 나이와 몸무게를 하나의 변수에 넣을 수 없을까?

// 2-2에 객체기반 sw  c++
// c==>c++
//struct(data) ==> class(data+function)

struct A {
	int age;
	int weight;
};

struct A person;
int       k;          //이거랑 같은 뜻임 

person.age = 21;
person.weight = 70.4;  //이렇게 값을 지정

typedef struct A {
	int age;
	int weight;
} PERSON_INFO;  // 별명지정 // 가능한 대문자 

struct A k;
PERSON_INFO k; // 두개 갗은 말


//p.84   구조체 대입과 비교연산 
PERSON_INFO a;
a.age = 20;
a.weight = 70.4;

PERSON_INFO b;
b = a;
b.age ? 20;
b.weight ? 70.4;   //대입은 가능 매우 유용

if(a==b)  // 이런비교는 안됨

if(a.age==b.age && a.weight == b.weight)  // 이렇게 비교하기 

// p.85 자기참조 구조체 별 5개 *****
//self-referencial structure

struct A {
	int age;
	int weight;
	struct A *k;  // 자기자신을 가르킨다. //struct A만 쓰는거는 안됨 주소 넣어주는건 가능 //본인의 주소를 넘겨주는겨 
};

// 구조채 배열 

struct A k[10];

// 3.5 포인터 pointer
//자바는 포인터를 없애고자 만든거라 포인터가 없음 
// c,c++--- >java ----> kotlin

// p.87 포인터의 개념
int a = 10;  //a는 사람이 보는거 컴퓨터는 주소로 본다. 우리의 변수명은 이룸 주소는 학번 etc. 이런 느낌으로 

int* pa = &a;

//p.90 배열과 포인터 
//배열의 이름은 그 배열이 저장된 메모리 시작주소 // 160줄이랑 다른걸 알아야함
int a[10];
int* pa;
pa = a; 

//p.91 구조제와 포인터 

struct A {
	int age;
	float weight;
};

struct A a;
struct A* pa;  //주소만 넣을 공간 
pa = &a;        //a의 시작주소 저장

//pa가 포인터니까 pa->age
//a가 변수면 . ; a.age
pa->age = 20;           
pa->weight = 75.4;

// p.92 함수포인터 읽어보기 

// p.92 포인터에대한 연산 

int* a;   //아파트 동 단위 907동 -> 908동
char* c;  //아파트 호단위 907동 101호 -> 102호 

a = 100;
a += 1; // ==>104

c = 100;
c += 1; // ==>101

//p.93 중간쯤

*p++
a = *p++;
//p가 가리키는 곳에가서 값을 가져와서 a에 넣고  p가 가리키는 곳의 값을 1만큼 증가
//===>
a = *p;
*p = *p + 1;    // 같은뜻인데 이게 더 좋음          // *가 오른쪽에 있으면 값을 집어 넣음  


*p--

(*p)++


// 3.6 동적메모리할당 
//<----> 정적메모리할당

int a[10]; // 정적 

maloc // 동적 
//memory allocation

int* p;  // 4바이트씩 뛰어넘겠다
p = (int*)malloc(40);  // 40바이트 할당  //malloc은 활광어와 같음 요리목적에 따라 캐스팅 가능
   // int 형으로 주세여 --> (int*)malloc(40)

char c;
c = (char*)malloc(100)

free(p); // 동적메모리 끝 // malloc없앤다, 쌍이 무조건 맞아야 한다.
free(c);


#include <stdio.h>
#include <malloc.h> //malloc할거면 이 헤더 써야됨

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

	 p->age = 22;  // 카운터로 연산 후 숫자 넣어주는 거는 -> 쓰고 그냥 넣어줄때는 . 쓴다.

	printf("%d\n", a.age);

	int* pa;
	pa = (int*) malloc(40);

} 
