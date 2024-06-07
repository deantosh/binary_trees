#include "binary_trees.h"

/**
 * valid_bst_helper - Helper function to check the BST property.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Pointer to the minimum value node allowed.
 * @max: Pointer to the maximum value node allowed.
 *
 * Return: 1 if tree is a valid BST, 0 otherwise.
 */

int valid_bst_helper(const binary_tree_t *tree,
					 const binary_tree_t *min, const binary_tree_t *max)
{
	if (tree == NULL)
		return (1);

	if (min != NULL && tree->n <= min->n)
		return (0);

	if (max != NULL && tree->n >= max->n)
		return (0);

	return (valid_bst_helper(tree->left, min, tree) &&
			valid_bst_helper(tree->right, tree, max));
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree.
 * @tree: is a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is valid BST, and 0 otherwise, If tree is NULL, return 0.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (valid_bst_helper(tree, NULL, NULL));
}
