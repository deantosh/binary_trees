#include "binary_trees.h"

/**
 * array_to_avl - Function builds an AVL tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: root node (success) or NULL (fails).
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *root, *node;
	size_t i;

	/*At the beggining: the tree is empty*/
	root = NULL;

	for (i = 0; i < size; i++)
	{
		/*insert the value to the AVL tree*/
		node = avl_insert(&root, array[i]);
		if (!node)
			return (NULL);
	}

	return (root);
}
