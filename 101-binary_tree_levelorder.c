#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"
/**
 * binary_tree_levelorder - goes thru binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *tmp;
	int front = 0, rear = 0;
	const binary_tree_t *queue[1024];

	if (!tree || !func)
		return;

	queue[rear++] = tree;
	while (front < rear)
	{
		tmp = queue[front++];
		func(tmp->n);
		if (tmp->left)
			queue[rear++] = tmp->left;
		if (tmp->right)
		queue[rear++] = tmp->right;
	}
}
