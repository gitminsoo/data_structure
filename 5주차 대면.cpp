// chap7. tree

// 7.1
// 
// linear data struture (배열 리스트 스택 큐 ---> 다 선형)
// 
// 지금부터 
// hierarchical data struture (계층척 데이터 구조)
// --> like 피라미드 (계층구조)
// 
// 대표적 계층구조 --> tree
// 
// node , edge , parent node , child node 
// ==> 탭 필기 보기
// 
// tree는 구조체로 만들거야
// head 처럼 중요한 포인터가 있는데
// 뿌리를 뜻하는 root라고 표현 
// 
// 

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
	struct node* nnode = 0;
	nnode = (struct node*)malloc(sizeof(struct node));
	nnode->left = nnode->right = 0;
	nnode->data = _data;

	if (root == 0)
	{
		root = nnode;
		return;
	}

	struct node* temp = root;

	while (1)
	{
		if (temp->data > nnode->data)   // 왼쪽으로 갈거
		{
			if (temp->left == 0)     // 비었네...앉아야징...
			{
				temp->left = nnode;
				return;
			}
			temp = temp->left;    // 한 층 내려가자
		}

		else  // 오른쪽으로 갈거
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




int main()
{
	addToBST(100);
	addToBST(50);
	addToBST(200);        // 입력순서대로 BST를 만듦


}