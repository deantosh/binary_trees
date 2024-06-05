#include "binary_trees.h"

/**
 * full_check_height - Helper function to check if tree is full
 *	and all leaves are at the same level.
 * @tree: Pointer to the root node.
 * @depth: Current depth in the tree.
 * @leaf_level: Pointer to the level of the first encountered leaf node.
 *
 * Return: 1 if the tree is full and all
 *	leaves are at the same level, otherwise 0.
 */
int full_check_height(const binary_tree_t *tree, int depth, int *leaf_level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
	{
		if (*leaf_level == -1)
		{
			*leaf_level = depth;
		}
		return (depth == *leaf_level);
	}

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (full_check_height(tree->left, depth + 1, leaf_level) &&
			full_check_height(tree->right, depth + 1, leaf_level));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_level = -1;

	if (tree == NULL)
		return (0);

	return (full_check_height(tree, 0, &leaf_level));
}
