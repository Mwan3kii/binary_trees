#include <stdlib.h>
#include "binary_trees.h"
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	size_t t;
	
	if (array == NULL || size == 0)
		return (NULL);
	
	for (t = 0; t < size; t++)
	{
		if (avl_insert(&root, array[t]) == NULL)
		{
			binary_tree_delete(root);
			return (NULL);
		}
	}
	return (root);
}
