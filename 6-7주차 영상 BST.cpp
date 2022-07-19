/*
  Binary Search Tree

  �������θ� ������� ������ BST => skewed BST (��ì�̷� �������)
  skewing �� �ֵ��� ����ð��� �پ���� ����  ==> ���߿� AVL�̶�°� ��� �̰ɷ� �ذ�

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

// �����͸� ���� ��带 ã�Ƽ� �ּ� ��ȯ;

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
  BST�� ���Ե� ��ü ����� ����
  �ּ� 0��

  recursion���� ������ž�
  1 + left(���ʿ� �ִ°� ��ü) + right(�����ʿ� �ִ°� ��ü)
*/

int cntBST(struct node* _r)   // �Է����ڴ� ��Ʈ�� ��      // �̰� �ǳ�
{
	// Ż������
	if (_r == 0)
	{
		return 0;
	}

	// �ڳ��� �����
	return 1 + cntBST(_r->left) + cntBST(_r->right);

}

//BST�� ���Ե� �͹̳� ����� �� // �͹̳γ��->�ڽ��� ���� ���

int cntTerminal(struct node* _r)
{
	if (_r == 0)
	{
		return 0;
	}

	if (_r->left == 0 && _r->right == 0)  // �ڱⰡ �͹̳� ���� ���� ������ �ڽ��� �����ϱ� �� ȥ�ڴٶ�� ������ 1��ȯ
	{
		return 1;
	}

	else // �ڽ��� ������ �ڽ��� �� �ؿ� �ִ� �ֵ��� ���� ��ȯ
	{
		return cntTerminal(_r->left) + cntTerminal(_r->right);
	}

}

// BST�� heihgt��?

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

	return 1 + ((left_height > right_height) ? left_height : right_height); // ���� ������ ũ�� ���� �ƴϸ� ���� ��ȯ
}

// �ȿ� �ִ� �����͸� �� ����غ��� �;��
// -> traversal 
// ������ �̷��� ���� 
// �����κ���.
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

// BST�� insert�� ���µ� delete�� �ִ�.

// 1. �͹̳� ��� ����Ʈ�� ����
// �θ� ����� �����͸� ������Ѵ�
// 
// delete
// 
// 1) �͹̳γ�� ����� : ���� ����, �θ��� ����
// 2) �ڽ� 1���� ��� ����� 
// --> ���γ���� �θ��尡 �ڽ��� �ڽ� ��带 ����Ű����
// 3) �ڽ� 2���� ��� ����� ( �� �ټ��� )
// --> �� ��带 ����°��� �ƴ� �ٸ� ���� ��ü�Ѵ� 
// 1�������� ���� ū ����(BST�� ���� �̿�) --> ���� ���� ��ü (copy) , 
// 1�� ������ ���� ���� (�̰Ÿ� ����°� ������? ����-> �͹̳� Ȥ�� �ڽ��� �ϳ���)
// or, 2�� ������ ���� ���� ���� --> ���� ���� ��ü(copy) , 2�������� ���� ����
// 
// ����� ���� ���� �߿� �Ѱ���
// ==> ���� ��尡 root
// �ڽ��� ���� root ( ����� root�� NULL)
// �ڽ��� �ϳ��� root
// �ڽ��� ���� root
//


// _r���� _data�� ���� ��带 ����
// ������ thankyou

// target -> t���
// t�� �θ� t_p ��带 �׻� ������ �־�� ��
//

void delFromBST(int _data, struct node* _r) // ��¥ ���� �غ���...
{
	struct node* t = _r; // t�� ������ ��带 ����Ŵ
	struct node* t_p = 0; // t_p�� �θ����� ������

	while (1)
	{
		if (t == 0)  // BST����ų� , _data��尡 ���� ���
		{
			return;
		}
		else if (t->data == _data) // ���� ��尡 �־ �������ϴ� ��� ==> ������ ����� �κ� // �׻� �ش��尡 root�� ���ܻ�Ȳ ���
		{
			// t�� ������ �ϴ� ��� target -> must be deleted
			//t_p�� t�� �θ�

			if (t->left == 0 && t->right==0) //���ڽ�
			{
				if (t == root) // t �� ����Ű�� ��尡 root
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
			else if (t->left != 0 && t->right == 0) // ���ڽ�
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
				else //t�� �θ��� ���� �ڽ�
				{
					t_p->right = t->left;
				}
				free(t);
				return;
			}

			else if (t->left == 0 && t->right != 0) // �����ڽ�
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
			else // ���ڽ� ���� �����  ==> ������ ���� �����ŷ� �����ϴ°ſ���
			{
				// ������ ���� ���� ū ��� �˰�
				// �� ������ ���� ���� ��带 ã�´�
				struct node* r = t->right;
				struct node* r_p = t; // ���� ������Ȳ? ����Ͱ� �� �������� ����ξ��� �̴�� �������� ������
				                      // r�� ��ü�� ��带 ����Ű�� r_p�� �� ����� �θ��带 ��´�. 
				while (r->left != 0) //���� ���� r��� ã���� ���� ��
				{
					r_p = r;
					r = r->left;
				}

				//r�� ���� ���� ��带 ����Ű�� ���� ==> �̽ļ��� �غ� ��;
				t->data = r->data;  // �̽� ���� �Ϸ�
				// ��� ���� �������� �����ڸ���
				// ������ ���� r_p�� ��Ʈ���� r�� r_p�� �����ʿ� �ִ� �� ��츦 ������� �Ѵ�.
				if (r_p->left == r) // r_p�� ��Ʈ�� �ƴ� ���
				{
					r_p->left = r->right;
				}
				else // ��忩�� r�� �����ʿ� ���� ���
				{
					r_p->right = r->right;
				}
				free(r);
				return;

			}
		}






		else  // data�� ã�� ���� �������� ����
		{
			t_p = t; // t_p�� t�� ������ġ�� ����Ų��.
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
		printf("data�� �����\n");
	}
	else {
		printf("%d (��)�� ã�ҽ��ϴ�\n", t->data);
	}

	int cnt = 0;
	cnt = cntBST(root);
	printf("����� ������ %d\n", cnt);

	printf("�͹̳� ����� ������ %d\n", cntTerminal(root));
	printf("bst height = %d\n", measurheight(root));

	inorderTraversal(root);
	printf("\n-----------\n");
	preorderTraversal(root);
	printf("\n-----------\n");
	postorderTraversal(root);*/



}
