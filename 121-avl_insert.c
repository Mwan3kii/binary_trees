#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
#include <stddef.h>
/**
 * binary_tree_height - Measures the height of a binary tree
 */
int binary_tree_balance_factor(const binary_tree_t *tree)
{
	return (tree != NULL ? binary_tree_height(tree->left) - binary_tree_height(tree->right) : 0);
}
/**
 * avl_insert_recursive - Inserts a value into an AVL tree recursively
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *avl_insert_recursive(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int bfactor;

	if (*tree == NULL)
		return (*new = binary_tree_node(parent, value));

	if ((*tree)->n > value)
	{
		(*tree)->left = avl_insert_recursive(&(*tree)->left, *tree, new, value);
		if ((*tree)->left == NULL)
			return (NULL);
	}
	else if ((*tree)->n < value)
	{
		(*tree)->right = avl_insert_recursive(&(*tree)->right, *tree, new, value);
		if ((*tree)->right == NULL)
			return (NULL);
	}
	 else
		 return (*tree);
	 bfactor = binary_tree_balance_factor(*tree);
	 if (bfactor > 1 && (*tree)->left->n > value)
		 *tree = binary_tree_rotate_right(*tree);
	 else if (bfactor < -1 && (*tree)->right->n < value)
		 *tree = binary_tree_rotate_left(*tree);
	 else if (bfactor > 1 && (*tree)->left->n < value)
	 {
		 (*tree)->left = binary_tree_rotate_left((*tree)->left);
		 *tree = binary_tree_rotate_right(*tree);
	 }
	 else if (bfactor < -1 && (*tree)->right->n > value)
	 {
		 (*tree)->right = binary_tree_rotate_right((*tree)->right);
		 *tree = binary_tree_rotate_left(*tree);
	 }
	 return (*tree);
}
/**
 * avl_insert - Inserts a value into an AVL tree.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;
	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	avl_insert_recursive(tree, *tree, &new, value);
	return (new);
}
