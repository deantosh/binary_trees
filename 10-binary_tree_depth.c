#include "binary_trees.h"

/**
 * binary_tree_depth - function to measuer depth of a node in a binary tree.
 * @tree: is a pointer to the node to measure the depth.
 *
 * Return: If tree is NULL, return 0.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	size_t depth_counter = 0;

	while (tree->parent)
	{
		depth_counter++;
		tree = tree->parent;
	}
	return (depth_counter);
}
