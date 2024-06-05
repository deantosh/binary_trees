#include "binary_trees.h"

/**
 * binary_tree_size - measeures the size of the binary tree.
 * @tree: is a pointer to root node of the tree to measure the size.
 *
 * Return: if tree is null, returns 0.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}
