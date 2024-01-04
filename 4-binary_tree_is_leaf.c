#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - Checks is a node is a leaf.
 * @node: The node to check.
 *
 * Return: 1 (true) or 0 (false).
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->left && !node->right)
		return (1);

	return (0);
}
