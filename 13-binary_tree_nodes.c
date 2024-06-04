#include "binary_trees.h"

/**
 * binary_tree_nodes - Function counts the nodes with at least 1 child
 *	in a binary tree.
 * @tree: A pointer to the root node of a tree to count number of nodes.
 *
 * Return: number of nodes (success) or 0 (fails).
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_count = 0, right_count = 0, current_count = 0;

	if (!tree)
		return (0);

	/*traverse the left subtree*/
	left_count = binary_tree_nodes(tree->left);

	/*traverse the right subtree*/
	right_count = binary_tree_nodes(tree->right);

	/*check if current node is parent*/
	if (tree->left || tree->right)
		current_count = 1;

	/*return total count*/
	return (current_count + left_count + right_count);
}
