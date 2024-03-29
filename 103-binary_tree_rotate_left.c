#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on binary tree
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->right == NULL)
		return (NULL);
	new_root = tree->right;
	tree->right = new_root->left;
	if (new_root->left != NULL)
		new_root->left->parent = tree;
	new_root->parent = tree->parent;
	if (tree->parent != NULL)
	{
		if (tree->parent->left == tree)
			tree->parent->left = new_root;
		else
			tree->parent->right = new_root;
	}
	tree->parent = new_root;
	new_root->left = tree;
	return (new_root);
}