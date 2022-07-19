#include <stdio.h>

// Hanoi의 탑

int num_steps = 0; //그릇 옮기는 횟수  //전역 변수로 놔죽;

/*
num은 몇개의 좁시를 옮기는가
from 어디로부터 (출발지) 0,1,2
to 여기로 ,(목적지)      0,1,2
temp 중간 작대기(경유지) 0,1,2
*/

void hanoi(int num, int from, int temp, int to)
{
	//1. 탈출조건... 현실로 돌아오자  //옮겨주는 조건 그 자체
	if (num == 1)
	{
		printf("%d작대기 ---> %d 작대기 옮겨요...\n", from, to);
		num_steps += 1;
		return;
	}


	//2. 상상력 파트..
	//코끼리 냉장고 넣기

	hanoi(num - 1, from, to, temp);  // 총 접시보다 하나 적은 탑을 from부터 경유지인 temp로 보내라 경유지는 목적지였던 to다
	hanoi(1, from, temp, to);        // 맨 밑에 있던 한 접시를 from에서 to로 보낸다 필요하면 temp거쳐라 
	hanoi(num - 1, temp, from, to);  // 먼저 temp쪽으로 옮겨두었던 남은 애들을 temp에서 to로 보낸다. 필요하면 from을 거쳐라
	return;
}

/*void becomeHuman(char* s)   // 교수님의 인생철학
{
	// 1.탈풀조건 
	if (s == "나아갈 떄와 머무를 때를 알자")
	{
		return;
	}

	// 2. 상상력 
	becomeHuman("잘 먹자");
	becomeHuman("열심히 하자");
	becomeHuman("예의를 지키자");

}*/


int main()
{
	 
	hanoi(5, 0, 1, 2);     //3개의 원반을 0번에서 1번을거쳐 2번으로 갈거임
	printf("총 %d회 그릇 옮겼어요\n", num_steps);
	return 0;
}


//recursion 상상을 잘 해야하지만 그만큼 현실에도 발을 담궈라

