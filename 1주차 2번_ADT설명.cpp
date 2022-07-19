// Abstract Data Type : ADT
//데이터와 operation이 모두 들어있는 데이터 타입 
// java , c++ ==> class

// C++ 객체기반 SW설계

// Data type
// //
// int : 정수를 잠을 수 있다.      -----> +,-,*,....
// char 
// float

// ADT
// imagine (데이터 , print , multiply)
// C++ Java Phyton , ... ==> Class ( data + function ) ==> 객체
// OOP : object or intend programming

//function....function....

// c언어에서 새로운 타입 만들기 
// 구조체 , struct

struct A{   // ====> class (java, c++)             //이건 안에 함수가 안들어있음 
	int i;
	char c;

};

struct A {   
	int i;
	char c;
	void showme() {             // 이렇게 함수가 안에 들어간게 ADT
		printf("%d", i);
	}

};

struct A a;     // 구조체로 새로운 a라는 변수를 만들고 밑은 선언 

a.i = 10;
a.c = 'a';


// Time Complexity : 알고리즘 , Big-O notation
