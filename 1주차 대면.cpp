// chap.2 순환
// recursion : 재귀

// recursion --> function ---> function call
// recursion -- function call itself
// 입력 function --> 출력
// c언어 : 함수들의 집합

// 컴파일은 이진수로 바꾸는 과정 c언어는 반드시 필요

/*int foo(int) {           //foo는 함수의 이름      //괄호 안은 입력 받는 데이터의 타입 //맨앞은 출력되는 데이터의 자료형
	//-------------  
	int k;
	k = foo(50);                // foo라는 함수가 foo를 사용             foo를 부르면 foo진행으로 루프 생성  
	return 0;                                                            // 이론적으로 끝나지 않지만 메모리 유한성으로 끝나긴 함
} */

/* int main()
{
	int result;

	result = foo(10);  //int 형
	//------
	return 0;
} */
// recursion 응용

#include <stdio.h>

int sumToN1(int n)            //반복문
{
	int sum = 0;// 합결과 저장 
	int i;
    for (i = 1; i <= n; i++)       // for문 이용
	{
		sum = sum + i;        // sum += i ;
	}

	return sum;
}

//s(3)
//3+s(2)
//3+2+s(1)
//3+2+1+s(0)
//..........              
//뒤를 생각하면 s-1 -2 -3 나오겠지? 근데 우리는 필요한게 0까지라고 보면 if문으로 조건을 만들어 줄 수 있음 55줄

int sumToN(int n)  // 재귀  
{
	//1부터 n까지 합 <--- i want
	// n 은 10이 들어올것
	//상상력 : 10까지 합이면 
	//만약 1부터 9까지 합을 알면 거기에 10만 더하면 됨 

	// 1. 탈출조건 ,  상상을 끝내는 조건
	if (n == 0)
	{
		return 0;
	}
	//2.상상력 부분
	return n + sumToN(n-1);               

	//재귀함수의 기본형태
}

int fac(int n)  // n!
{ 
	if (n == 1)
	{
		return 1;
	}
	return n * fac(n - 1);
}


int main()
{
	int result;
	int result2;

	result = sumToN(10);
	printf("1부터 10까지의 합은 : %d\n", result);

	result2 = fac(10);
	printf("1부터 10까지의 곱은 : %d\n", result2);
}

//재귀의 장단점
// p,51  "순환알고리즘의 성능" 끝부분
//장점 : 알고리즘 구현이 매우 쉬움 , 직관적
//단점 ; 1) 수행시간이 오래걸리고  
//          함수호출 자체가 시간이 많이 소요되는 행위 main과 함수를 오가기 떄문
//       2) 메모리 소모가 많아 
//          함수 수행을 위해 필요한 데이터를 이동하는데 그 데이터들이 그대로 있어서 메모리가 많이 소모됨
//       잘못하면 프로그램 죽음

//p.52
// recursion을 이용한 거듭제곱
//2^n을 구하자 
 
//s(8) = 2^8                     //이거를 이용해서 더 간단히 함
//==> 4^4 (2^(2*4))  
//==> 16^2

int s(int n)
{
	if (n == 0)   //탈출조건 
	{
		return 1;
	}
	return 2 * s(n - 1);   //상상력
}

int s1(int m,int n)  //m^n
{
	if (n == 0)   //탈출조건 
	{
		return 1;
	}

	

	return m * s1(m,n - 1);   //상상력
}




int s1(int m, int n)  //m^n    이거 이해 안돼
{
	if (n == 1)   //탈출조건 
	{
		return m;
	}

	if (n % 2 == 0)
	{
		return (s1(m*m,n/2));
	}

	else
	{
		return m * (s1(m*m,(n-1)/2));        //else 면 홀수라는 소린데 이게 왜 이렇게 돼야하는거지
	}

}


//n번째 fibo는 0,1,1,2,3,5,8......      // 0이 0번째 항임
//            [0][1][2][3]......
int fibo(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}

	return fibo(n - 1) + fibo(n - 2);
}