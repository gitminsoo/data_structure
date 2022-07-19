#include <stdio.h>

//��͸� �̿��ϸ� 
//1. 1���� n������ ��

int sumN(int na)
{ 
	if (na == 0)            //  (n<=0)
	{
		return 0;
	}

	return na + sumN(na - 1);
}

//2. 2�� �ŵ� ���� 2^n

int TwoSquareN(int nb)
{
	if (nb==0)
	{
		return 1;
	}
	return 2 * TwoSquareN(nb - 1);
}

//3. m^n

int MsquareN(int nc, int nd)         // �̰ŵ� ������ 3-2������ �̰ź��� �޸� �ҿ䰡 ������ ������ 
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

int fiboN(int nnb)   //0�� 0��° ����
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

	Msquare = MsqN(c, d);   //MsquareN �Լ� �ᵵ ��

	fact = factN(a);

	fibo = fiboN(a);

	printf("a : %d\na���� �� : %d\n2�� a�� : %d\n%d�� %d �� : %d\na�� factorial : %d\na��° �Ǻ���ġ������ : %d\n",
		a , sum,square,c,d,Msquare,fact,fibo);
}
