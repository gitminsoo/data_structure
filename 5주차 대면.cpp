// chap7. tree

// 7.1
// 
// linear data struture (�迭 ����Ʈ ���� ť ---> �� ����)
// 
// ���ݺ��� 
// hierarchical data struture (����ô ������ ����)
// --> like �Ƕ�̵� (��������)
// 
// ��ǥ�� �������� --> tree
// 
// node , edge , parent node , child node 
// ==> �� �ʱ� ����
// 
// tree�� ����ü�� ����ž�
// head ó�� �߿��� �����Ͱ� �ִµ�
// �Ѹ��� ���ϴ� root��� ǥ�� 
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
		if (temp->data > nnode->data)   // �������� ����
		{
			if (temp->left == 0)     // �����...�ɾƾ�¡...
			{
				temp->left = nnode;
				return;
			}
			temp = temp->left;    // �� �� ��������
		}

		else  // ���������� ����
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
	addToBST(200);        // �Է¼������ BST�� ����


}