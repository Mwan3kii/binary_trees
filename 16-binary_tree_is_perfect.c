#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_height - Sees the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 * Return: Height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);
	return (1 + (left_height > right_height ? left_height : right_height));
}
/**
 * binary_tree_is_perfect - Checks if binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is perfect
 * 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t h = binary_tree_height(tree);
	size_t nodes = binary_tree_size(tree);
	size_t perfect_nodes = (1 << h) - 1;

	return (nodes == perfect_nodes);
}
/**
 * binary_tree_size - Does the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
