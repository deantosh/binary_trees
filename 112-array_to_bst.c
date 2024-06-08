#include "binary_trees.h"

/**
 * array_to_bst - Function builds a Binary Search Tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of element in the array.
 *
 * Return: root node (success) or NULL (fails).
 */
bst_t *array_to_bst(int *array, size_t size)
{
	size_t i;
	bst_t *root = NULL, *node;

	if (!array)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		/*create BST -- add array value*/
		node = bst_insert(&root, array[i]);
		/*if duplicate value found*/
		if (!node)
			return (NULL);
	}
	return (root);
}
