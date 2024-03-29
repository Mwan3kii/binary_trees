#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * bst_insert - Inserts a value in a Binary Search Tree
 * @tree: Double pointer to the root node of the BST to insert the value
 * @value: Value to store in the node to be inserted
 *
 * Return: A pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *parent;

	if (tree == NULL)
	return (NULL);
	parent = NULL;
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (new_node == NULL)
			return (NULL);
		*tree = new_node;
		return (new_node);
	}
	parent = *tree;
	while (parent)
	{
		if (value == parent->n)
			return (NULL);
		if (value < parent->n)
		{
			if (parent->left == NULL)
			{
				new_node = binary_tree_node(parent, value);
				if (new_node == NULL)
					return (NULL);
				parent->left = new_node;
				return (new_node);
			}
			parent = parent->left;
		}
		else
		{
			if (parent->right == NULL)
			{
				new_node = binary_tree_node(parent, value);
				if (new_node == NULL)
					return (NULL);
				parent->right = new_node;
				return (new_node);
			}
			parent = parent->right;
		}
	}
	return (NULL);
}
