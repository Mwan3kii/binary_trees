#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <limits.h>
/**
 * binary_tree_is_avl_recursive - Checks if a binary tree is a valid AVL tree
 * @tree: A pointer to the root node of the tree to check
 * @min: The minimum value the node can have
 * @max: The maximum value the node can have
 * @height: The current height of the tree
 * Return: If valid - 1
 */
int binary_tree_is_avl_recursive(const binary_tree_t *tree, int min, int max, int *height)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
	{
		*height = 0;
		return (1);
	}
	if (tree->n < min || tree->n > max)
		return (0);
	if (!binary_tree_is_avl_recursive(tree->left, min, tree->n - 1, &left_height) ||
			!binary_tree_is_avl_recursive(tree->right, tree->n + 1, max, &right_height))
		return (0);
	*height = (left_height > right_height ? left_height : right_height) + 1;
	if (left_height - right_height > 1 || right_height - left_height > 1)
		return (0);
	return (1);
}
/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree
 * tree: A pointer to the root node of the tree to check
 * Return: -1 if valid -0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height = 0;
	
	if (tree == NULL)
		return (0);
	return (binary_tree_is_avl_recursive(tree, INT_MIN, INT_MAX, &height));
}
