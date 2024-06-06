#include "binary_trees.h"

/**
 * binary_tree_is_complete - Function checs if a binary tree is
 *	complete. Each node
 *		has 2 children or zero.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 (complete) or 0 (incomplete).
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	int node_count = 0;

	if (!tree)
		return (0);

	/*get number of node in a binary tree*/
	node_count = number_of_nodes(tree);

	/*if odd*/
	return (tree_is_complete(tree, 0, node_count));
}

/**
 * number_of_nodes - Function finds the number of children
 *	a given node has.
 * @tree: The node whose children to find.
 *
 * Return: number of nodes (always).
 */
int number_of_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + number_of_nodes(tree->left) + number_of_nodes(tree->right));
}

/**
 * tree_is_complete - Function checks if tree is complete using the
 *		depth first approach.
 * @tree: The tree to check.
 * @index: The index of the parent node.
 * @node_count: The total number of nodes in a binary tree.
 *
 * Return: 1 (complete) or 0 (incomplete).
 */
int tree_is_complete(const binary_tree_t *tree, int index, int node_count)
{
	if (!tree)
		return (1);

	if (index >= node_count)
		return (0);

	return (tree_is_complete(tree->left, 2 * index + 1, node_count) &&
		tree_is_complete(tree->right, 2 * index + 2, node_count));
}
