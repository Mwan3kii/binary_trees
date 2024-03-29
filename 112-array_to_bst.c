#include <stdlib.h>
#include "binary_trees.h"
#include "binary_trees.h"

/**
 * array_to_bst - Builds a Binary Search Tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 *
 * Return: A pointer to the root node of the created BST, or NULL on failure
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;
	size_t p;

	if (array == NULL || size == 0)
		return (NULL);

	for (p = 0; p < size; p++)
	{
		if (bst_insert(&root, array[p]) == NULL)
			return (NULL);
	}
	return (root);
}
