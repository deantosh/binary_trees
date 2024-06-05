#include "binary_trees.h"

/**
 * binary_tree_balance - Function measures the balance factor of a
 *		binary tree.
 * @tree: A pointer to the root nodes of the tree to measure the
 *	balance factor.
 *
 * Return: balance factor (success) or 0 (fails).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	/*get subtrees height*/
	if (tree->left)
		left_height = tree_height(tree->left) + 1;
	if (tree->right)
		right_height = tree_height(tree->right) + 1;

	/*get the balance factor*/
	return (left_height - right_height);
}


/**
 * tree_height - Function gets the height of a tree.
 * @tree: A pointer to the root node of the tree to find height.
 *
 * Return: height(always).
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	/*traverse the left subtree*/
	if (tree->left)
		left_height = tree_height(tree->left) + 1;

	/*traverse the right subtree*/
	if (tree->right)
		right_height = tree_height(tree->right) + 1;

	/*return the maximum height*/
	return (left_height > right_height ? left_height : right_height);
}
