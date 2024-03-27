#include "binary_trees.h"
/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor node
 * or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const
binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *p1, *p2;

	if (!first || !second)
		return (NULL);
	p1 = first;
	while (p1)
	{
		p2 = second;
		while (p2)
		{
			if (p1 == p2)
				return ((binary_tree_t *)p1);
			p2 = p2->parent;
		}
		p1 = p1->parent;
	}
	return (NULL);
}
