#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: is the pointer to the node to check
 *
 * Return: 1 if node is root, othrewise 0. if node is null, return 0.
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	/*If node has parent*/
	if (node->parent)
		return (0);

	return (1);
}
