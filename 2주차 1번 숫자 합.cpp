#include <stdio.h>

int sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + sum(n - 1);
}

int main()
{
	int result = 0;
	result = sum(5);
	printf("sum is %d\n", result);
}