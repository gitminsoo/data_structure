// p.96 五乞軒 疑旋 拝雁税 森

/* #include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 10

int main()
{
	int* p;

	p = (int*)malloc(SIZE * sizeof(int));


	if (p == NULL)           // 疑旋拝雁戚 照鞠檎
	{
		fprintf(stderr, "五乞軒亜 採膳背辞 拝雁拝 呪 蒸柔艦陥.\n");    // 神嫌坪球 幻窮陥. //stderr亜 妊層神嫌窒径,, 獄遁元 蒸戚 但 句趨捜 
		exit(1);            // 纏窒庚                                                        //fprintf猿走澗 侯虞亀 吃牛
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

// p.97 疑旋五葛軒 拝雁 森
// studentTag戚硯税 姥繕端 照拭 戚硯 10鯵壕伸 蟹戚 gpa幻級嬢辞 student 戚硯 竺舛
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
	s->age = 20;  //戚惟 (*s).age虞澗 源引 旭製 

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

//疑嘘 malloc 竺誤

/* malloc->疑旋拝雁

獣什奴戚 叔楳鞠壱 赤澗 亀掻拭 五乞軒研 幻球澗 誤敬嬢戚陥.

0 けけけけ 4 けけけけ 8 けけけけ ... 100 けけけけ
a け け け け
int main(void)
{

	int a = 5;

	int* p; 疑旋拝雁聖 床形檎, 巷繕闇 匂昔斗 痕呪拭陥亜 拝雁背醤掬.
		訊劃 ?
		malloc->覗稽益掘袴亜 識澱廃 幻鏑税 痕呪研 爽社因娃 嬢拠亜拭陥亜 幻級嬢兜澗闇汽, malloc精 爽社研 鋼発背.
		--------------------------------
		int n;

	5

		scanf("%d", &n);

	int* p;
	p = (int*)malloc(sizeof(int) * n); -> 4 Byte * 5 = 20 Byte. int int 5鯵幻鏑税 因娃.

		int** p;

	p = (int**)malloc(sizeof(int*) * n);
	--->戚 坪球澗 戚薦 戚掻壕伸 幻級凶 彰陥檎, 戚 陥製坪球澗

		for (int i = 0; i < n; i++)
		{
			p[i] = (int*)malloc(sizeof(int) * 3);
		}

	戚係惟 馬檎,

		p[n][3] 戚 鞠澗暗.しせ ?


		int 5鯵研 隔聖 呪 赤澗暗績.p[5];
	------------------------------ -

		け->け->け->け->け->け->け->...->け



		int n[1000]

		free(p)
		return 0;
} */

//疑嘘 2掻 壕伸 疑旋拝雁 坪球 

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