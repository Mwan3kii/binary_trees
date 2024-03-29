#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * bst_remove - Removes a node from a Binary Search Tree
 * @root: Pointer to root node of the tree where you will remove a node
 * @value: The value to remove in the tree
 * Return: A pointer to the new root node
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return NULL;
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else {
		if (root->left == NULL)
		{
			bst_t *tmp = root->right;
			free(root);
			return tmp;
		}
		else if (root->right == NULL)
		{
			bst_t *tmp = root->left;
			free(root);
			return tmp;
		}
		bst_t *tmp = bst_minimum(root->right);
		root->n = tmp->n;
		root->right = bst_remove(root->right, tmp->n);
	}
	return root;
}
/**
 * bst_minimum - Finds the minimum node in a Binary Search Tree
 * @node: Pointer to the root node of the tre
 * Return: A pointer to the minimum node
 */
bst_t *bst_minimum(bst_t *node)
{
	bst_t *curr = node;

	while (curr && curr->left)
		curr = curr->left;
	return curr;
}
