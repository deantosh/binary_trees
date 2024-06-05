#include "binary_trees.h"

/**
 * binary_tree_is_full - Function checks if a  binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 (full) or 0 (not full).
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	/*If the tree is NULL*/
	if (!tree)
		return (0);

	/*If tree has leaf node, it is full*/
	if (!tree->left && !tree->right)
		return (1);

	/*If tree has both left and right child, it is full*/
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	/*If tree has one child, is not full*/
	return (0);
}
