#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_root - Checks if a given node is root.
 * @node: The node to check.
 *
 * Return: 1 (true) or 0 (false).
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (1);

	return (0);
}
