//
// chapter 11 hashing
// 
// 엄청나게 빠른 검색
// 
// 암호 보안에도 기본적으로 사용
// 
// 예를들어 어떤 숫자가 포함되어있는지 확인
// n개의 숫자들 중 한 숫자 찾기
// 
// 모든거 다 훑기 --> O(n)
// ==> 제일 무식한 방법
// 
// 소팅 후 훑기 
// ==> 찾을때 중간 숫자 찾아서
// ==> 이진 탐색 하기 ==> binary search tree 방식
// ==> O(log2 n) ==> 왜 이거인지는 확안
// 
// 그럼 다 소팅하고 해요??
// 근데 얘는 소팅에 재한 시간 O(nlog n)이 더해짐
// 
// hashing 의 등장
// ==> 속도 O(1)  ==> 추구할 극강의 알고리즘
// 입력의 수와 상관없이 동일한 시간이 걸림 
// 그 시간이 하루던 이틀이던 1분이던 같기만 하면 O(1)
// 
// O(1) --> 알고리즘의 최상위==> 추구해야함
// ==> 극강의 알고리즘
// 
// 배열 100 만들어서 100으로 모듈러 연산해서 그 칸에 저장
// 
// if 78 을 찾고 싶어 ==> 100으로 나눈 나머지 78
// 배열의 78번째 칸에 가서 있으면 있는거임
// 
// 근데 큰 문제가 있음 ==> 데이터의 충돌 
// collision (충돌) -> 한 칸을 사용해야해서 충돌이 생김
// 
// 저장 되어야 할 곳의 위치를 계산하는 함수
// Hash function : 100으로 나누돈 200으로 나누던 그건 알아서
// 
// Hash table : 데이터 저장되는 공간
// 저장되는 데이터는 (key , value)
// key : hash function이 적용되는 값
// value : 실제로 저장되는 값
// 
// ex) 201901738 (김민수 , 부천 , 남)
//        key           value
// 
// key를 100으로 하면 38번에 저장 되는것 
// 
// 찾을때 38번 찾아가서 value 찾으면 됨
// 
// 파이썬 : dict == dictionary == Hash table == map
// 파이썬 딕트의 문제는 메모리 사용량이 많다는 점
// 
// 
// hash function : key로부터 저장될 곳의 위치를 계산하는 함수
//					--> 정해진 것이 없고 key에 따라 결정
//			100 - 김철수
//			200 - 이영미
//			300 - 이한수
//			==> 100으로 나누면 collision 생겨서 각 자리를 더해서 하는 경우 많음
//			
//			==> 시험은 교수님이 hashing func값 주어줌 그거로 만들기
// 
// 
// 
// collision
// 막는 3가지 방법
// 
// 1. (제일 무식) table을 무진장 크게 만든다.
//    ==> 메모리 낭비가 엄청남
// 
// 2. linear probing
//		--> hashing을 반복해서 적용
//		if) hash func : %7
//		key : 8 ==> 1 칸으로 
//		key : 1 ==> 1 로 가야하는데 collision 생김
//			h(1)+1 % 7 = 2 (저장)
// 결국 저장이 안되면 바로 밑의 칸으로 이동하며 빈곳으로 들어감
// 
// 
// 3.chaining (python dict)
//	hash table (ht)
//	 ht의 한 칸을 linked list로 만들기 (노드붙이는 식으로)
//	근데 찾을 때 링크드리스트 만들면 찾는거 차피 오래걸리지 않나요?
//	리스트가 많이 생기지 않아서 시간 오래 안걸림
//

// Hasing의 성능 분석
// 
// loding destiny == loading factor : 적재 비율, 적재 밀도
// 공간 사용의 효율성 ==> 높을 수록 좋은거 
// 
// 10칸 있는데 10칸 다 쓰면 loading factor = 1
// 
// 100칸 있는데 10칸 쓰면 loading factor = 0.1;
//

//
// 12장 탐색
// 
// 12.1 탐색이란
// ==> 위치 찾아가기
//  
// 12.2 정렬 안된거 탐색
// ==> O(n)
// 
// 12.3 정렬 된거 탐색
// ==> O(log2 N)
// 
// 12.4 이진 탐색
// ==> O(log2 N)
// 1024==> 512 ==> 256 ==> 128 ==> 64==> 32 ==> 16 8 4 2 1
// 총 11번인데 맨마지막 1이니까 할 필요 없음 증 10번 
// log2 1024 = 10
// 
// 12.3.3 색인순차탐색 : index sequential search
// ==> 책이 12장까지 있는데 어떤 사진을 찾고싶어
// ==> 어느 장인지 알면 맨 앞에서 그 장을 찾아서 그곳부터 sequential하게 찾기 시작
// ==> 목차만들듯이 만들고 그거 본 후 찾기 
// ==> 정렬된 배열로 
// ==========> database에서 indexing이라는 개념이 나오는데 이런개념임
// 
// 12.3.4 interpolation search (보간 탐색)
//	일단 소팅된 배열
//	처음과 끝의 수를 보고 비율적으로 확인해서 거기부터 시작
//	비례식으로 확인 ==> 어림잡아 확인하는 search 법
// 
// 12.4 균형이진 탐색트리 AVL Tree
// Adelson-Velskii, Landis, 1962
// 
// 이진 탐색트리 보완 
// 이진 트리의 문제는 한쪽에 쏠림이 생김
// ==> 결국 sequential search와 다를게 없을때가 생김
// ==> 중간 중간 root를 바꾸며 균형을 잡아주고 
// ==> search time도 줄일 수 있음
//