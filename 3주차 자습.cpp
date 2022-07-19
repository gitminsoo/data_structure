// #define _CRT_SECURE_NO_WARNINGS

#pragma warning(disable:4996)

#include <stdio.h>

//구조체 정의 

/* struct stu {

	char name[10];
	int age;     // 멤버 피드라고 함 
	float height;

};

struct coord {
	int x;
	int y;
};

struct tri {
	int w;
	int h;
};

int main()
{
	
	struct stu a = { "john",20,175.0 };
	struct tri t = { 10,4 };

	a.age = 22;

	printf("student : name %s age : %d height : %f\n", a.name, a.age, a.height);

}


//strcmp(a,a) en 두 스트링 비교하는데 같으면 0반환
//strcpy(a,b) b를 a에 복사하는 것

*/
#include <math.h>

/* struct third_d {
	int x;
	int y;
	int z;
};

int main()
{
	third_d a;
	third_d b;

	a.x = 1;
	a.y = 2;
	a.z = 3;

	b.x = 4;
	b.y = 5;
	b.z = 7;

	int d = pow((b.x - a.x), 2) + pow((b.y - a.y), 2) + pow((b.z - a.z), 2); //math.h 헤더 시용

	printf("%f\n", sqrt(d) );

} */



#include <stdlib.h>  //malloc,free
//동적 할당 
// malloc,free

/* int main()
{
	int* p = (int*)malloc(10*sizeof(int));  //동적할당 받는 메모리의 맨앞 주소를 반환하는 거 
								   //malloc은 항상 void* 형태로 반환 되므로 자기가 쓸 형태로 캐스팅 해야됨  (int*)
	                               //할당된 공간은 항상 연속되어서 만들어짐 
	        // 이 줄에 p를 재정의 후 free해버리면 이 전의 p메모리들이 free가 안되므로 memory leak현상이 생김
	// 여기에 q=p 만들어 놓고 free(p)를 먼저 시켜버리면 dangling pointer현상이 생김 
	// 즉, 반납도 순서에 맞춰서 하기 
	//malloc free가 어려워지는 이유 

	*p = 50;
	*(p + 1) = 51;

	free(p);  // os가 동적메모리 할당을 관리함 
	          // freㄷ 안하면 메모리 누수현상이 생김 메모리 부족한 현상  memory leak
	          //그니까 잊지 말고 하기 


	return 0;

} */

#include<string.h>

struct info {
	char name[10];
	int age;
};
typedef struct info INFO;

/* int main()
{
	INFO* p = (INFO*)malloc(sizeof(INFO) * 10);
	INFO* temp = 0;
	temp = (p + 1); //이렇게 하면 p+1자리에 temp쓰면 됨

	strcpy(p->name, "tom");
	p->age = 20;
	printf("%s\n%d\n", p->name, p->age);
	printf("%s\n%d\n", p[0].name, p[0].age);

	strcpy((p + 1)->name, "john");
	(p + 1)->age = 22;
	printf("%s\n%d\n", (p+1)->name, (p+1)->age);
	printf("%s\n%d\n", p[1].name, p[1].age);

	return 0;
}*/

//ragged array
// 배열의 끝이 정렬되지 않은 동적할당
//tom과 park이라는 다 다른 길이의 배열 받을 수 있음 
//tom은 문자열의끝인 \0을 포함해서 4개 
//park은 문자열의끝인 \0을 포함해서 5개 

/* int main()
{
	char* arr[2];
	char* temp = 0;

	//tom
	temp = (char*)malloc(4);
	strcpy(temp, "tom");
	arr[0] = temp;


	//john
	temp = (char*)malloc(5);
	strcpy(temp, "john");
	arr[1] = temp;

	printf("%s ===> %s\n", arr[0], arr[1]);

	return 0;
} */

//__________________ 책 문제__________________

// 26. 배열 x={1,2,3,4,5,6}
//pointer p
//p=&x[2]
//*(p+3) * *(p-2)

/* int main()
{
	int x[6] = { 1,2,3,4,5,6 };

	int* p = &x[2];

	printf("%d\n%d\n%d\n", *(p + 3), *(p - 2), (*(p + 3)) * (*(p - 2)));
} */

//27. p.99 12

/* struct quest12 {
	int i1;
	char str[20];
};

int main()
{
	quest12* a;
	a = (struct quest12*)malloc(sizeof(struct quest12));

	a->i1 = 100;
	strcpy(a->str, "just testing!");

	printf("%d\n%s\n", a->i1, a->str);

	free(a);
} */


//28. p.98.06

/* struct mmm {
	float real;
	float imaginary;
};

typedef struct mmm complex;

int main()
{
	complex c1;
	complex c2;

} */

//29 30. p.98.05 +???

/* struct birth {
	int month;
	int day;
	int year;
};

struct person {
    char name[20];
	int age;
	float pay;
	struct birth b;
};

int main()
{
	struct person p1 = { "kim",20,100.0f,{9,19,2000} }; //안에 넣는 것은 이중 브라켓으로 하면 됨

} */

// 포인터 한문제 구조체 한문제

//_______수업 중 만든 코드 중요점 정리____________________________

// 배열은 call by reference 즉 값이 그대로 넘어가고 
// 값을 그냥 넘기는 것은 call by value 로서 값을 복사해서 넘긴다.

// 자기 참조 구조체 
// 교수님 픽 별 5개 
// 자기 자신을 부르는 구조체  ex)

/* struct A {
	int age;
	int weight;
	struct A* k;// 여기서 구조체의 포인터는 넘길 수 있지만 구조체 자체는 넘기지 못한다 
	           // 즉 struct* A 는 되지만 struct A 이 자체만 넘기는 것은 불가능 
};

int main()
{
	struct A a;
	struct A* pa;

	pa = &a;

	a.age = 20;                             // 포인터가 아닌 그냥 변수에 값을 넣을 떄는 .을 쓴다 
	a.weight = 70;

	printf("%d   %d\n", a.age, a.weight);

	pa->age = 23;                 // 포인터 변수에 값을 넣을 때는 ->를 쓴다.
	pa->weight = 73;             // 현재 pa는 a의 주소를 가지고 있기때문에 이렇게 하면 위에서 지정한 a의 값이 바뀌게된다.
	 
	printf("____________변신___________\n");
	printf("%d   %d\n", pa->age, pa->weight);
	return 0;
} */

// 동적 메모리 할당은 <stdlib.h> 헤더파일 시용

/* typedef struct A {
	int cnt;
	int age;
}P_INFO;

int main()
{
	 P_INFO a;
	 a.cnt = 1;
	 a.age = 20;

	 printf("%d   %d\n", a.cnt, a.age);
	 
	 P_INFO* p;
	 p = &a;

	 p->cnt = 2;
	 p->age = 22;
	
	 printf("%d   %d\n", a.cnt, a.age);

	 P_INFO* pa = NULL;
	 pa = (P_INFO*)malloc(sizeof(P_INFO));

	 pa->cnt = 3;
	 pa->age = 23;

	 printf("%d   %d", pa->cnt, pa->age);

	 free(pa);

} */

// 두 점사이의 거리 

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable : 4996)

struct dem_p {
	int x;
	int y;
	int z;
};

int main()
{
	struct dem_p a;
	struct dem_p b;

	scanf("%d %d %d %d %d %d", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);

	int sum = pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);

	float ans = sqrt(sum);

	printf("%.3f\n", ans);
}
*/

// 구조체 포인터의 동적할당

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning (disable : 4996)

typedef struct info {
	char name[10];
	int age;
	float pay;
}INFO_H;

int main()
{
	INFO_H a;
	scanf("%s %d %f", a.name, &a.age, &a.pay);

	INFO_H* b;
	b = (INFO_H*)malloc(sizeof(INFO_H));
	scanf("%s %d %f", b->name, &b->age, &b->pay);

	printf("\n%s %d %.3f\n", a.name, a.age, a.pay);
	printf("\n%s %d %.3f\n", b->name, b->age, b->pay);
}
*/

// 두 점사이의 거리 

/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma warning (disable : 4996)

struct dem_p {
	int x;
	int y;
	int z;
};

int main()
{
	struct dem_p a;
	struct dem_p b;

	scanf("%d %d %d %d %d %d", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);

	int sum = pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);

	float ans = sqrt(sum);

	printf("%.3f\n", ans);
}
*/

/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#pragma warning (disable : 4996)

typedef struct info {
	char name[10];
	int age;
	float pay;
}INFO_H;

int main()
{
	INFO_H a;
	scanf("%s %d %f", a.name, &a.age, &a.pay);

	INFO_H* b;
	b = (INFO_H*)malloc(sizeof(INFO_H));
	scanf("%s %d %f", b->name, &b->age, &b->pay);

	printf("\n%s %d %.3f\n", a.name, a.age, a.pay);
	printf("\n%s %d %.3f\n", b->name, b->age, b->pay);
}
*/

/* #include <stdio.h>
#include <stdlib.h>

#pragma warning (disable:4996)

typedef struct ins {
	char name[10];
	int age;
}INSTA;

int main()
{
	INSTA a;

	scanf("%s %d", &a.name, &a.age);

	printf("%s \n%d\n", a.name, a.age);

} */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

struct none {
	int age;
	char name[10];
};

typedef none INFO;

int main()
{
	INFO* a;

	a = (INFO*)malloc(2*sizeof(INFO));

	a->age = 26;
	(a + 1)->age = 27;

	strcpy(a->name, "king");
	strcpy((a+1)->name, "queen");

	printf("%d\n%s\n", a->age, a->name);
	printf("%d\n%s\n", (a+1)->age, (a+1)->name);
	free(a);

} */

/* #include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)

int main()
{
	char* name[2];
	char* tmp;

	tmp = (char*)malloc(4);
	strcpy(tmp, "kim");
	name[0] = tmp;

	tmp = (char*)malloc(5);
	strcpy(tmp, "king");
	name[1] = tmp;

	printf("%s %s", name[0], name[1]);

	free(tmp);
} */

// 오류남
/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#pragma warning (disable:4996)

int main()
{
	char* cnt[2];
	char* tmp;

	char name[10];
	char mame[10];

	scanf("%s %s", name, mame);

	int i;
	i = strlen(name);
	int j;
	j = strlen(mame);

	tmp = (char*)malloc(i+1);
	tmp = name;
	cnt[0] = tmp;

	tmp = (char*)malloc(j + 1);
	tmp = mame;
	cnt[1] = tmp;

	printf("%s\n%s\n", cnt[0], cnt[1]);

	free(tmp);
}  */

//두점 사이의 거리

/*
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#pragma warning(disable:4996)

struct DEM_P {
	int x;
	int y;
	int z;
};

int main()
{
	DEM_P a;
	DEM_P b;

	scanf("%d %d %d %d %d %d", &a.x, &a.y, &a.z, &b.x, &b.y, &b.z);

	int sum = pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2);
	float point = sqrt(sum);

	printf("%.3f", point);


} */

/* #include <stdio.h>
#include <stdlib.h>

typedef struct dkanrjsk {
	int age;
	int tall;
}CRI;

int main()
{
	CRI* a;
	a = (CRI*)malloc(2*sizeof(CRI));

	a->age = 20;
	a->tall = 180;

	(a + 1)->age = 25;
	(a + 1)->tall = 185;

	printf("%d %d\n%d %d", a->age, a->tall, (a + 1)->age, (a + 1)->tall);

	free(a);

} */

/* #include <stdio.h>
#pragma warning (disable:4996)

int add(int* arr, int na)
{
	int sum = 0;
	for (int i = 0; i < na; i++)
	{
		sum = sum + arr[i];
	}
	return sum;
}

int main()
{
	int a;
	int n[10];
	int cnt = 0;

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a);
		n[i] = a;
		cnt += 1;
	}
	int sum = 0;

	sum=add(n, cnt);

	printf("%d", sum);


} */