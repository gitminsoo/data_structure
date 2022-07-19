#include <stdio.h>

//재귀를 이용하며 
//1. 1부터 n까지의 합

int sumN(int na)
{ 
	if (na == 0)            //  (n<=0)
	{
		return 0;
	}

	return na + sumN(na - 1);
}

//2. 2의 거듭 제곱 2^n

int TwoSquareN(int nb)
{
	if (nb==0)
	{
		return 1;
	}
	return 2 * TwoSquareN(nb - 1);
}

//3. m^n

int MsquareN(int nc, int nd)         // 이거도 맞지만 3-2번으로 이거보다 메모리 소요가 적도록 만들어보기 
{
	if (nd == 0)
	{
		return 1;
	}

	return nc * MsquareN(nc, nd - 1);
}

int MsqN(int nc, int nd)
{
	if (nd == 1)
	{
		return nc;
	}

	else if ((nd % 2) == 0)
	{
		return MsqN(nc * nc, nd / 2);
	}

	else
	{
		return nc* MsqN(nc * nc, (nd-1) / 2);
	}
}

//4. n!

int factN(int nna)
{
	if (nna == 1)
	{
		return 1;
	}

	return nna * factN(nna - 1);
}


//5. fibo

int fiboN(int nnb)   //0이 0번째 항임
{
	if (nnb == 0)
	{
		return 1;
	}

	else if (nnb == 1)
	{
		return 1;
	}

	return fiboN(nnb - 1) + fiboN(nnb - 2);
}




int main()
{
	int a = 10;
	int sum = 0;
	int square = 0;

	int c = 2;
	int d = 5;
	int Msquare = 0;

	int fact = 0;

	int fibo = 0;

	sum = sumN(a);
	square = TwoSquareN(a);

	Msquare = MsqN(c, d);   //MsquareN 함수 써도 됨

	fact = factN(a);

	fibo = fiboN(a);

	printf("a : %d\na까지 합 : %d\n2의 a승 : %d\n%d의 %d 승 : %d\na의 factorial : %d\na번째 피보나치수열은 : %d\n",
		a , sum,square,c,d,Msquare,fact,fibo);
}
