// 혼자 만들어보는 하노이탑 recursion

// hanoi tower
/* #include <stdio.h>

int cnt = 0;

void hanoi(int n, int s, int t, int e)    //n개 start temp end
{
	if (n == 1)                // 판이 하나 남으면 종료
	{
		printf("%d 에서 %d 로 이동하라\n", s, e);
		cnt += 1;
		return;
	}


	hanoi(n - 1, s, e, t);   //맨 밑의 하나 뺴고 나머지를 시작점에서 t로 이동할건데 필요하면 끝점을 경유해라 
	hanoi(1, s, t, e);       //그 나머지 하나를 시작점에 끝으로 이동할건데 필요하면 t를 경유해라
	hanoi(n - 1, t, s, e);   //t에 있던 애들을 끝점으로 보낼건데 필요하면 s점을 이용해라 
	return;
}

int sumN(int na)
{

	if (na == 0)
	{
		return 0;
	}

	return na + sumN(na - 1);
}



int main()
{
	int a = 3;
	int b = 0;
	int c = 1;
	int d = 2;

	hanoi(a, b, c, d);
	printf("\n총 %d 번 움직였습니다.\n", cnt);

	int sum = 0;
	sum = sumN(a);
	printf("%d 까지의 합 %d\n", a, sum);
	 
}  */

// recursion 응용
 
/* #include <stdio.h>

// n까지의 합

int sumN(int na)
{

	if (na == 0)
	{
		return 0;
	}


	return na + sumN(na - 1);
}

// 2의 n승 

int squareN(int nb)
{

	if (nb == 0)
	{
		return 1;
	}
	
	return 2 * squareN(nb - 1);
}

// m의 n제곱

int MsquareN(int nc, int nd)
{
	if (nd == 0)
	{
		return 1;
	}

	return nc * MsquareN(nc, nd - 1);
}

// m의 n제곱 2

int MsquareN2(int nna, int nnb)
{
	if (nnb == 0)
	{
		return 1;
	}

	else if ((nnb % 2) == 0)
	{
		return MsquareN2(nna * nna, (nnb / 2));
	}

	else
	{
		return nna * MsquareN2(nna * nna, (nnb - 1) / 2);
	}
}

// factorial

int fact(int ma)
{
	if (ma == 1)
	{
		return 1;
	}

	return ma * fact(ma - 1);
}

// fibo

int fibo(int mb)
{
	if (mb == 1)
	{
		return 1;
	}

	else if (mb == 2)
	{
		return 1;
	}

	return fibo(mb - 1) + fibo(mb - 2);
}


int main()
{
	int a = 10;
	
	int sum = 0;
	sum = sumN(a);

	printf("\n%d 까지의 합은 %d 입니다.\n", a, sum);

	int square = 0;
	square = squareN(a);
	printf("\n2의 %d제곱은 %d 입니다.\n", a, square);

	int b = 5;
	int c = 2;
	int Msquare = 0;
	Msquare = MsquareN(b,c);
	printf("\n%d의 %d제곱은 %d 입니다.\n", b, c,Msquare);

	
	int Msquare2 = MsquareN2(b, c);
	printf("\n%d의 %d제곱은 %d 입니다.\n", b, c, Msquare2);

	int factN = 0;
	factN = fact(a);
	printf("\n%d의 factorial은 %d 입니다.\n", a, factN);

	int fiboN = 0;
	fiboN = fibo(a);
	printf("\n%d번째 fibo수열은 %d 입니다.\n",a,fiboN );



}   */

// recursion 응용

// 까지 합

/* #include <stdio.h>

int sumN(int na)
{
	if (na == 0)
	{
		return 0;
	}

	return na + sumN(na - 1);
}

// 2의 n승

int squareN(int nb)
{
	if (nb == 0)
	{
		return 1;
	}

	return 2 * squareN(nb - 1);
}

// m의n승

int MsquareN(int nc, int nd)
{
	if (nd == 0)
	{
		return 1;
	}

	return nc * MsquareN(nc, nd - 1);
}

//m의 n승 2

int MsquareN2(int nna, int nnb)
{
	if (nnb == 0)
	{
		return 1;
	}

	else if ((nnb % 2) == 0)
	{
		return MsquareN(nna * nna, (nnb / 2));
	}

	else
	{
		return nna * MsquareN(nna * nna, ((nnb - 1) / 2));
	}
}

// 피보

int fibo(int fa)
{
	if (fa == 0)
	{
		return 0;
	}
	else if (fa == 1)
	{
		return 1;
	}

	return fibo(fa - 1) + fibo(fa - 2);
}

// 팩토리얼

int fact(int fb)
{
	if (fb == 0)
	{
		return 1;
	}

	return fb * fact(fb - 1);
}


int main()
{
	int a ;
	int b ;

	//scanf_s("%d", &a, sizeof(a));
	//scanf_s("%d", &b, sizeof(b));

	scanf_s("%d %d", &a, &b);

	int sum = 0;
	sum = sumN(a);

	int square = 0;
	square = squareN(a);

	int Msquare = 0;
	Msquare = MsquareN(b,a);

	int Msquare2 = 0;
	Msquare2 = MsquareN2(b, a);

	int fiboa = 0;
	fiboa = fibo(a);

	int facta = 0;
	facta = fact(a);

	printf("%d 까지의 합 : %d\n", a, sum);
	printf("2의 %d 제곱 : % d\n", a, square);
	printf("%d의 %d 제곱 : %d\n", b, a,Msquare);
	printf("%d의 %d 제곱 : %d\n", b, a,Msquare2);
	printf("%d 번째 피보나치수열 : %d\n", a, fiboa);
	printf("%d 팩토리얼 : %d\n", a, facta);


} */

//하노이탑

/* #include<stdio.h>

int cnt = 0;

void hanoi(int n, int s, int t, int e)
{
	if (n == 1)
	{
		printf("%d 에서 %d 로 이동하라.\n", s, e);
		cnt += 1;
		return;
	}


	hanoi(n - 1, s, e, t);
	hanoi(1, s, t, e);
	hanoi(n - 1, t, s, e);
	return;
}

int main()
{
	int a = 3;
	int st = 1;
	int tmp = 2;
	int end = 3;

	hanoi(a, st, tmp, end);
	printf("\n%d 회 움직였습니다.\n", cnt);
} */

//하노이 탑

/* #include <stdio.h>

int cnt = 0;

void hannoi(int n, int s, int t, int e)
{
	if (n == 1)
	{
		printf("%d 을 %d 로 이동해라.\n", s, e);
		cnt += 1;
		return;
	}

	hannoi(n - 1, s, e, t);
	hannoi(1, s, t, e);
	hannoi(n - 1, t, s, e);
	return;
}

int main()
{
	int a = 3;
	int b = 1;
	int c = 2;
	int d = 3;

	hannoi(a, b, c, d);
	printf("\n%d 번 이동하였습니다.\n", cnt);


} */

// 1/n 의 합

/* #include <stdio.h>

int sumN(int na)
{
	if (na == 0)
	{
		return 0;
	}

	return na + sumN(na - 1);
}

float divN(int nb)
{
	if (nb == 1)
	{
		return 1;
	}

	return (float)1 / nb + divN(nb - 1);  // static_cast<float>(1)  이거는 float형으로 강제 형변환 시키는것과 같은 효과
}


int main()
{
	int a = 5;

	int sum = 0;
	sum = sumN(a);

	printf("%d 까지의 합 : %d\n", a, sum);

	float div = 0;
	div = divN(a);

	printf("1부터 1/%d 까지의 합 : %f\n", a, div);

} */

// 하노이탑

/* #include <stdio.h>

int cnt = 0;

void hanoi(int n,int s,int t,int e)
{
	if (n == 1)
	{
		printf("%d 에서 %d 로 이동하시오.\n", s, e);
		cnt += 1;
		return;
	}

	hanoi(n - 1, s, e, t);
	hanoi(1, s, t, e);
	hanoi(n - 1, t, s, e);
	return;
}

int main()
{
	int n = 3;

	int s = 1, t = 2, e = 3;

	hanoi(n, s, t, e);
	printf("\n%d 번 움직였습니다.\n", cnt);
} */

/* #include <stdio.h>

int cnt = 0;

void hanoi(int n, int s, int t, int e)
{
	if (n == 1)
	{
		printf("%d 에서 %d 로 이동하였습니다.\n", s, e);
		cnt += 1;
		return;
	}

	hanoi(n - 1, s, e, t);
	hanoi(1, s, t, e);
	hanoi(n - 1, t, s, e);
}

int main()
{
	int n = 3;
	int s = 1, t = 2, e = 3;

	hanoi(n, s, t, e);
	printf("%d 회 움직였습니다.\n", cnt);
} */

/* #include <stdio.h>

int sumN(int na)
{
	if (na == 0)
	{
		return 0;
	}
	return na + sumN(na - 1);
}

int main()
{
	int a = 10;
	int sum = 0;

	sum = sumN(a);

	printf("%d 까지의 합은 %d \n", a, sum);
}  */

