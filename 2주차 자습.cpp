// ȥ�� ������ �ϳ���ž recursion

// hanoi tower
/* #include <stdio.h>

int cnt = 0;

void hanoi(int n, int s, int t, int e)    //n�� start temp end
{
	if (n == 1)                // ���� �ϳ� ������ ����
	{
		printf("%d ���� %d �� �̵��϶�\n", s, e);
		cnt += 1;
		return;
	}


	hanoi(n - 1, s, e, t);   //�� ���� �ϳ� ���� �������� ���������� t�� �̵��Ұǵ� �ʿ��ϸ� ������ �����ض� 
	hanoi(1, s, t, e);       //�� ������ �ϳ��� �������� ������ �̵��Ұǵ� �ʿ��ϸ� t�� �����ض�
	hanoi(n - 1, t, s, e);   //t�� �ִ� �ֵ��� �������� �����ǵ� �ʿ��ϸ� s���� �̿��ض� 
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
	printf("\n�� %d �� ���������ϴ�.\n", cnt);

	int sum = 0;
	sum = sumN(a);
	printf("%d ������ �� %d\n", a, sum);
	 
}  */

// recursion ����
 
/* #include <stdio.h>

// n������ ��

int sumN(int na)
{

	if (na == 0)
	{
		return 0;
	}


	return na + sumN(na - 1);
}

// 2�� n�� 

int squareN(int nb)
{

	if (nb == 0)
	{
		return 1;
	}
	
	return 2 * squareN(nb - 1);
}

// m�� n����

int MsquareN(int nc, int nd)
{
	if (nd == 0)
	{
		return 1;
	}

	return nc * MsquareN(nc, nd - 1);
}

// m�� n���� 2

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

	printf("\n%d ������ ���� %d �Դϴ�.\n", a, sum);

	int square = 0;
	square = squareN(a);
	printf("\n2�� %d������ %d �Դϴ�.\n", a, square);

	int b = 5;
	int c = 2;
	int Msquare = 0;
	Msquare = MsquareN(b,c);
	printf("\n%d�� %d������ %d �Դϴ�.\n", b, c,Msquare);

	
	int Msquare2 = MsquareN2(b, c);
	printf("\n%d�� %d������ %d �Դϴ�.\n", b, c, Msquare2);

	int factN = 0;
	factN = fact(a);
	printf("\n%d�� factorial�� %d �Դϴ�.\n", a, factN);

	int fiboN = 0;
	fiboN = fibo(a);
	printf("\n%d��° fibo������ %d �Դϴ�.\n",a,fiboN );



}   */

// recursion ����

// ���� ��

/* #include <stdio.h>

int sumN(int na)
{
	if (na == 0)
	{
		return 0;
	}

	return na + sumN(na - 1);
}

// 2�� n��

int squareN(int nb)
{
	if (nb == 0)
	{
		return 1;
	}

	return 2 * squareN(nb - 1);
}

// m��n��

int MsquareN(int nc, int nd)
{
	if (nd == 0)
	{
		return 1;
	}

	return nc * MsquareN(nc, nd - 1);
}

//m�� n�� 2

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

// �Ǻ�

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

// ���丮��

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

	printf("%d ������ �� : %d\n", a, sum);
	printf("2�� %d ���� : % d\n", a, square);
	printf("%d�� %d ���� : %d\n", b, a,Msquare);
	printf("%d�� %d ���� : %d\n", b, a,Msquare2);
	printf("%d ��° �Ǻ���ġ���� : %d\n", a, fiboa);
	printf("%d ���丮�� : %d\n", a, facta);


} */

//�ϳ���ž

/* #include<stdio.h>

int cnt = 0;

void hanoi(int n, int s, int t, int e)
{
	if (n == 1)
	{
		printf("%d ���� %d �� �̵��϶�.\n", s, e);
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
	printf("\n%d ȸ ���������ϴ�.\n", cnt);
} */

//�ϳ��� ž

/* #include <stdio.h>

int cnt = 0;

void hannoi(int n, int s, int t, int e)
{
	if (n == 1)
	{
		printf("%d �� %d �� �̵��ض�.\n", s, e);
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
	printf("\n%d �� �̵��Ͽ����ϴ�.\n", cnt);


} */

// 1/n �� ��

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

	return (float)1 / nb + divN(nb - 1);  // static_cast<float>(1)  �̰Ŵ� float������ ���� ����ȯ ��Ű�°Ͱ� ���� ȿ��
}


int main()
{
	int a = 5;

	int sum = 0;
	sum = sumN(a);

	printf("%d ������ �� : %d\n", a, sum);

	float div = 0;
	div = divN(a);

	printf("1���� 1/%d ������ �� : %f\n", a, div);

} */

// �ϳ���ž

/* #include <stdio.h>

int cnt = 0;

void hanoi(int n,int s,int t,int e)
{
	if (n == 1)
	{
		printf("%d ���� %d �� �̵��Ͻÿ�.\n", s, e);
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
	printf("\n%d �� ���������ϴ�.\n", cnt);
} */

/* #include <stdio.h>

int cnt = 0;

void hanoi(int n, int s, int t, int e)
{
	if (n == 1)
	{
		printf("%d ���� %d �� �̵��Ͽ����ϴ�.\n", s, e);
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
	printf("%d ȸ ���������ϴ�.\n", cnt);
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

	printf("%d ������ ���� %d \n", a, sum);
}  */

