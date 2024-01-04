#include "binary_trees.h"

/**
 * binary_tree_depth - Measures the depth of a node in a binary
 *			tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: depth (if node exists) or  0 (not exists or NULL)
*/
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth = binary_tree_depth(tree->parent) + 1;

	return (depth);
}
