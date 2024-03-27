#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 * or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *ptr1, *ptr2;
	if (!first || !second)
		return (NULL);
	ptr1 = first;
	while (ptr1)
	{
		ptr2 = second;
		while (ptr2)
		{
			if (ptr1 == ptr2)
				return ((binary_tree_t *)ptr1);
			ptr2 = ptr2->parent;
		}
		ptr1 = ptr1->parent;
	}
	return (NULL);
}
