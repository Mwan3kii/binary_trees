#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

size_t avl_height(const avl_t *tree);
int avl_balance_factor(const avl_t *tree);
int _max(int a, int b);

avl_t *avl_remove(avl_t *root, int value)
{
	if (root == NULL)
		return NULL;
	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (root->left == NULL || root->right == NULL)
		{
			avl_t *temp = root->left ? root->left : root->right;
			if (temp == NULL)
			{
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else
		{
			avl_t *temp = root->right;
			while (temp->left != NULL)
				temp = temp->left;
			root->n = temp->n;
			root->right = avl_remove(root->right, temp->n);
		}
	}
	if (root == NULL)
		return NULL;
	root->height = 1 + _max(avl_height(root->left), avl_height(root->right));
	int balance = avl_balance_factor(root);
	if (balance > 1 && avl_balance_factor(root->left) >= 0)
		return binary_tree_rotate_right(root);
	if (balance > 1 && avl_balance_factor(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return binary_tree_rotate_right(root);
	}
	if (balance < -1 && avl_balance_factor(root->right) <= 0)
		return binary_tree_rotate_left(root);
	if (balance < -1 && avl_balance_factor(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return binary_tree_rotate_left(root);
	}
	return root;
}
