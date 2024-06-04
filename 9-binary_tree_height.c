#include "binary_trees.h"

/**
 * binary_tree_height - Measures te height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: binary tree height (success) or 0 (fails).
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	/*traverse the left subtree*/
	if (tree->left)
		left_height = binary_tree_height(tree->left) +  1;

	/*traverse the right subtree*/
	if (tree->right)
		right_height = binary_tree_height(tree->right) + 1;

	/*find max*/
	return (left_height > right_height ? left_height : right_height);
}
