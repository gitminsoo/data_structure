/*
  Binary Search Tree

  한쪽으로만 만들어진 안좋은 BST => skewed BST (꼬챙이로 껴진모양)
  skewing 된 애들은 수행시간이 줄어들지 않음  ==> 나중에 AVL이라는거 배움 이걸로 해결

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* root = 0;

void addToBST(int _data)
{
	struct node* nnode = (struct node*)malloc(sizeof(struct node));
	nnode->data = _data;
	nnode->left = nnode->right = 0;

	if (root == 0)
	{
		root = nnode;
		return;
	}

	struct node* temp = root;
	while (1)
	{
		if (temp->data > nnode->data)
		{
			if (temp->left == 0)
			{
				temp->left = nnode;
				return;
			}
			temp = temp->left;
		}

		else if (temp->data < nnode->data)
		{
			if (temp->right == 0)
			{
				temp->right = nnode;
				return;
			}
			temp = temp->right;
		}


	}

}

// 데이터를 가진 노드를 찾아서 주소 반환;

struct node* findNode(int _data)
{
	struct node* cur = root;

	while (1)
	{
		if (cur == 0)
		{
			return 0;
		}
		if (cur->data == _data)
		{
			return cur;
		}

		if (cur->data > _data)
		{
			cur = cur->left;
		}

		else
		{
			cur = cur->right;
		}
	}
}

/*
  BST에 포함된 전체 노드의 갯수
  최소 0개

  recursion배운거 써먹을거야
  1 + left(왼쪽에 있는거 전체) + right(오른쪽에 있는거 전체)
*/

int cntBST(struct node* _r)   // 입력인자는 루트를 줌      // 이게 되네
{
	// 탈출조건
	if (_r == 0)
	{
		return 0;
	}

	// 코끼리 냉장고
	return 1 + cntBST(_r->left) + cntBST(_r->right);

}

//BST에 포함된 터미널 노드의 수 // 터미널노드->자식이 없는 노드

int cntTerminal(struct node* _r)
{
	if (_r == 0)
	{
		return 0;
	}

	if (_r->left == 0 && _r->right == 0)  // 자기가 터미널 노드면 왼쪽 오른쪽 자식이 없으니까 나 혼자다라는 뜻으로 1반환
	{
		return 1;
	}

	else // 자식이 있으면 자신의 양 밑에 있는 애들을 세서 반환
	{
		return cntTerminal(_r->left) + cntTerminal(_r->right);
	}

}

// BST의 heihgt은?

int measurheight(struct node* _r)
{

	int left_height = 0;
	int right_height = 0;

	if (_r == 0)
	{
		return 0;
	}

	left_height = measurheight(_r->left);
	right_height = measurheight(_r->right);

	return 1 + ((left_height > right_height) ? left_height : right_height); // 왼이 오보다 크면 왼을 아니면 오를 반환
}

// 안에 있는 데이터를 다 출력해보고 싶어용
// -> traversal 
// 세가지 이론이 있음 
// 탭으로보자.
// 1. inorder traversal  2. preorder traversal  3.postorder traversal
// 
//

// inorder
// L - me - R

void inorderTraversal(struct node* _r)
{
	if (_r == 0)
	{
		return;
	}

	inorderTraversal(_r->left);
	printf("%d ", _r->data);
	inorderTraversal(_r->right);

}

// preorder
// me - L - R

void preorderTraversal(struct node* _r)
{
	if (_r == 0)
	{
		return;
	}

	printf("%d ", _r->data);
	preorderTraversal(_r->left);
	preorderTraversal(_r->right);
}

// postorder
// L - R - me

void postorderTraversal(struct node* _r)
{
	if (_r == 0)
	{
		return;
	}

	postorderTraversal(_r->left);
	postorderTraversal(_r->right);
	printf("%d ", _r->data);
}

// BST는 insert는 없는데 delete가 있다.

// 1. 터미널 노드 딜리트는 쉬움
// 부모 노드의 포인터를 봐줘야한다
// 
// delete
// 
// 1) 터미널노드 지우기 : 제일 간단, 부모노드 수정
// 2) 자식 1개인 노드 지우기 
// --> 본인노드의 부모노드가 자신의 자식 노드를 가리키게함
// 3) 자식 2개인 노드 지우기 ( 별 다섯개 )
// --> 그 노드를 지우는것이 아닌 다른 수로 대체한다 
// 1번집안의 제일 큰 숫자(BST의 성질 이용) --> 위의 숫자 대체 (copy) , 
// 1번 집안의 숫자 프리 (이거를 지우는건 쉽나요? ㅇㅇ-> 터미널 혹은 자식이 하나임)
// or, 2번 집안의 제일 작은 숫자 --> 위의 숫자 대체(copy) , 2번집안의 숫자 프리
// 
// 고려할 사항 제일 중요 한가지
// ==> 지울 노드가 root
// 자식이 없는 root ( 지우고 root를 NULL)
// 자식이 하나인 root
// 자식이 둘인 root
//


// _r에서 _data를 가진 노드를 삭제
// 없으면 thankyou

// target -> t노드
// t의 부모 t_p 노드를 항상 가지고 있어야 함
//

void delFromBST(int _data, struct node* _r) // 진짜 많이 해보기...
{
	struct node* t = _r; // t는 삭제할 노드를 가르킴
	struct node* t_p = 0; // t_p는 부모노드의 포인터

	while (1)
	{
		if (t == 0)  // BST비었거나 , _data노드가 없는 경우
		{
			return;
		}
		else if (t->data == _data) // 지울 노드가 있어서 지워야하는 경우 ==> 실제로 지우는 부분 // 항상 해당노드가 root인 예외상황 고려
		{
			// t가 지워야 하는 대상 target -> must be deleted
			//t_p는 t의 부모

			if (t->left == 0 && t->right==0) //무자식
			{
				if (t == root) // t 가 가르키는 노드가 root
				{
					root = 0;
					free(t);
					return;
				}
				if (t_p->left == t)
				{
					t_p->left = 0;
					free(t);
					return;
				}
				else
				{
					t_p->right = 0;
					free(t);
					return;
				}

				
			}
			else if (t->left != 0 && t->right == 0) // 왼자식
			{
				if (t == root)
				{
					root = t->left;
					free(t);
					return;
				}

				if (t_p->left == t)
				{
					t_p->left = t->left;
				}
				else //t는 부모의 오른 자식
				{
					t_p->right = t->left;
				}
				free(t);
				return;
			}

			else if (t->left == 0 && t->right != 0) // 오른자식
			{
				if (t == root)
				{
					root = t->right;
					free(t);
					return;
				}
				if (t_p->left == t)
				{
					t_p->left = t->right;
					free(t);
					return;
				}

				else
				{
					t_p->right = t->right;
					free(t);
					return;
				}
			}
			else // 쌍자식 정말 어려움  ==> 오른쪽 제일 작은거로 땜빵하는거에용
			{
				// 오른쪽 집의 제일 큰 어른을 뵙고
				// 그 집안의 제일 작은 노드를 찾는다
				struct node* r = t->right;
				struct node* r_p = t; // 지금 무슨상황? 지울것과 그 오른쪽을 묶어두었고 이대로 왼쪽으로 내려서
				                      // r은 대체할 노드를 가르키고 r_p는 그 노드의 부모노드를 얻는다. 
				while (r->left != 0) //제일 작은 r노드 찾으러 가는 길
				{
					r_p = r;
					r = r->left;
				}

				//r은 제일 작은 노드를 가르키고 있음 ==> 이식수술 준비 끝;
				t->data = r->data;  // 이식 수술 완료
				// 배신 시작 조직에서 꼬리자르기
				// 보통의 경우와 r_p가 루트여서 r이 r_p의 오른쪽에 있는 두 경우를 나누어야 한다.
				if (r_p->left == r) // r_p가 루트가 아닌 경우
				{
					r_p->left = r->right;
				}
				else // 헤드여서 r이 오른쪽에 붙은 경우
				{
					r_p->right = r->right;
				}
				free(r);
				return;

			}
		}






		else  // data를 찾기 위해 내려가는 과정
		{
			t_p = t; // t_p는 t의 직전위치를 가르킨다.
			if (t->data > _data)
			{
				t = t->left;
			}
			else
			{
				t = t->right;
			}
		}
	}
    
}

	
int main()
{
	struct node* t = 0;

	addToBST(100);
	addToBST(50);
	addToBST(200);
	addToBST(10);
	addToBST(250);
	addToBST(150);

	delFromBST(150,root);

	inorderTraversal(root);

	/*printf("%d \n", root->data);
	printf("%d \n", root->left->data);
	printf("%d \n", root->right->data);

	t = findNode(10);

	if (t == 0)
	{
		printf("data가 없어용\n");
	}
	else {
		printf("%d (을)를 찾았습니다\n", t->data);
	}

	int cnt = 0;
	cnt = cntBST(root);
	printf("노드의 갯수는 %d\n", cnt);

	printf("터미널 노드의 갯수는 %d\n", cntTerminal(root));
	printf("bst height = %d\n", measurheight(root));

	inorderTraversal(root);
	printf("\n-----------\n");
	preorderTraversal(root);
	printf("\n-----------\n");
	postorderTraversal(root);*/



}
