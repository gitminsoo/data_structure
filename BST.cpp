#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* root = 0;

void add(int _data)
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
		if (temp->data > _data)
		{
			if (temp->left == 0)
			{
				temp->left = nnode;
				return;
			}
			temp = temp->left;
		}
		if (temp->data < _data)
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

void inorder(struct node* _r)
{
	if (_r == 0)
	{
		return;
	}
	inorder(_r->left);
	printf("%d ", _r->data);
	inorder(_r->right);

}

void del(int _data, struct node* _r)
{
	if (_r == 0)
	{
		return;
	}
	struct node* temp = _r;
	struct node* temp_p = 0;

	while (1)
	{
		if (temp == 0)
		{
			return;
		}
		if (temp->data == _data)
		{
			if (temp->left == 0 && temp->right == 0)
			{
				if (temp == _r)
				{
					free(temp);
					_r = 0;
					return;
				}
				if (temp_p->left == temp)
				{
					temp_p->left = 0;
					free(temp);
					return;
				}
				if (temp_p->right == temp)
				{
					temp_p->right = 0;
					free(temp);
					return;
				}
			}
			if (temp->left != 0 && temp->right == 0)
			{
				if (temp == _r)
				{
					_r = _r->left;
					free(temp);
					return;
				}
				if (temp_p->left == temp)
				{
					temp_p->left = temp->left;
					free(temp);
					return;
				}
				if (temp_p->right == temp)
				{
					temp_p->right = temp->left;
					free(temp);
					return;
				}
			}
			if (temp->left == 0 && temp->right != 0)
			{
				if (temp == _r)
				{
					_r = _r->right;
					free(temp);
					return;
				}
				if (temp_p->left == temp)
				{
					temp_p->left = temp->right;
					free(temp);
					return;
				}
				if (temp_p->right == temp)
				{
					temp_p->right = temp->right;
					free(temp);
					return;
				}
			}
			if (temp->left != 0 && temp->right != 0)
			{
				struct node* k = temp->right;
				struct node* k_p = k->left;

				while (k->left != 0)
				{
					k_p = k;
					k = k->left;
				}
				temp->data = k->data;
				if (k_p->left == k)
				{
					k_p->left = k->right;
					free(k);
					return;
				}
				if (k_p->right == k)
				{
					k_p->right = k->right;
					free(k);
					return;
				}
			}

		}
		else
		{
			if (temp->data > _data)
			{
				temp_p = temp;
				temp = temp->left;
			}
			if (temp->data < _data)
			{
				temp_p = temp;
				temp = temp->right;
			}
		}
	}
}

int main()
{
	add(100);
	add(50);
	add(200);
	add(10);
	add(250);
	add(150);
	inorder(root);

	printf("\n");

	del(100, root);
	inorder(root);

	printf("\n");

	del(200, root);
	inorder(root);
}