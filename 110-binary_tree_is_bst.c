#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * is_bst_util - Check if a binary tree is a valid BST
 * @tree: Pointer to root node of the tree to check
 * @min: Minimum value
 * @max: Maximum value
 *
 * Return: 1 if the tree is a valid BST
 * 0 otherwise
 */
int is_bst_util(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n < min || tree->n > max)
		return (0);
	return (is_bst_util(tree->left, min, tree->n - 1) &&
		is_bst_util(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_bst - Checks if a binary tree is a valid BST
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is a valid BST
 * 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_bst_util(tree, INT_MIN, INT_MAX));
}
