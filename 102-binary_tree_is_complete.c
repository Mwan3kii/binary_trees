#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_is_complete - sees if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_is_complete_recursive(tree, 0, binary_tree_size(tree)));

}
/**
 * binary_tree_is_complete_recursive - does recursive
 * @tree: Pointer to the root node of the tree to check
 * @index: Current index of the node being checked
 * @node_count: Total number of nodes in the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */
int binary_tree_is_complete_recursive(const binary_tree_t *tree,
					unsigned int index,
					unsigned int node_count)
{
	if (!tree)
		return (1);
	if (index >= node_count)
		return (0);
	return (binary_tree_is_complete_recursive(tree->left,
						2 * index + 1, node_count) &&
		binary_tree_is_complete_recursive(tree->right, 2 * index + 2, node_count));
}
/**
 * binary_tree_size - size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree
 * or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
