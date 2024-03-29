//
// quik sort
// 
// 정렬계의 명품
// nlogn
// 
// 직관적으로 이해
// 할것들이 있는데 그러면 퀵소트는 기본 아이디어가 
// 쪼개기
// 
// 좋은 알고리즘은 무엇일까? --> 쪼개는 것은 컴퓨터에서 가장 
// 전략적인 활동
// ==> divide and conquer (코딩계의 유명한 말)
// --> 간단한 알고리즘에 효과적
// --> 복잡한거는 이제 딥러닝으로 함
// 
// 숫자가 쭉 잇으면 반으로 쪼갬
// 가운데가 기준점
// 작은 숫자들은 왼쪽으로
// 큰 숫자는 오른쪽으로 
// --> 이건 나중에 알려줌
// 
// 이렇게 한 후에 반복
// 
// 반 중에 반을 나눠 큰애 작은애 비교 재위치 
// ==> 계속 반복
// 
// -----> 정렬 완료
// 
// pivot --> 기준점
// 
// 내용은 영상으로 
// --> 진짜 중요하니까 마음대로 쓸 수 있도록 외워야함
// 
// 


//
// cahp. 10
// 그래프
// 
// 나중애 11장 해싱을 배움
// 여기서는 쉡고 구현도 간단한데
// 블록체인에 들어가서 반드시 잘 이해해야함
// 
// 12장 탐색
// BST나옴
// 
// 
// 10장은 진짜 중요하고 어렵다
// 지금까지 베이스캠프 
// 그래프는 진짜 등산 하는거
// 정상 정복
// 
// 그래프 
// -- BFS
// -- DFS
// -- MST
// -- Dijkstra (최단경로 알고리즘) ==> 실제 회단경로 나오는거
// ==> 네비 지하철 그런거
// ==> 얘에서 파생이 A* 가 나오는데 이게 자율주행 자동차에 들어감
// 
// 진짜 가장 중요한 내용
// 
// 지금까지 자료구조는 얘를위한 준비운동 수준
// 
// Graph 
// 사람이 있고 친구가있어 그 친구가 나를 알고 
// 나는 다른 친구를 알고 등등 --> 동그라미 선으로 잇는 표현 가능
// SLL DLL 다 그래프임
// 
// 관계를 나타내는것은 다 그래프라고 생각하기
// 
// vertex (node)
// edge (next,prev,link)
// 
// 원모양은 vertex
// 선은 edge -> vertex를 이어주는 애들
// 
// p. 400
// 
// directed graph,
// undirected graph
// ==> 방향성이 있는 edge를 사용하는 애들을 directted graph
// ==> 방향성이 없어서 왔다 갔다 가능한 애들을 undirected graph
// 
// weighted graph
// 예를들어 부평에서 인천시청 까지 30분
// 인천시청에서 인입까지 20 분이라고 할때
// 이 거리, 비용 등등을 합쳐서 graph를 만든게 weighted graph
// 
// subgraph(401p.)
// 그래프의 일부분
// 
// adjacent vertex(인접노드)
// edge로 직접 연결된 vertex를 나타냄
// 
// in-degree ==> directed graph에서 들어오는 화살표의 갯수
// out-degree ==> 나가는 화살표의 갯수
// 
// ==> ver에서 다른 ver로 가는길을 path라고 함
// ==> 가는길이 중복되더라도 가는 모든길은 path
// simple path ==> 겹치는 path가 없이 진행되는 path
// shortest path ==> 가장 빠른 방법 (시간이 적거나 비용이 적거나 등등)
// 
// cycle
// 나한테서 시작해서 다른 ver 거쳐서 나로 돌아오는게 있으면 cycle이 있다고 표현
// 
// 
// 특수한 그래프
// 모든 ver들이 서로서로 연결되어있다
// ==> complete graph
// 
// 그래프를 구현 
// 0번부터 3번의 ver
// edge 는 3개
// 구현 방법==> 1. 2차원배열 이용 2. linked list
// 
// dense graph --> 2차원배열   ;; edge 많음
// sparse graph --> linked list ;; edge 적음
//

