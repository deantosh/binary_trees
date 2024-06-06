#include "binary_trees.h"

/**
 * binary_tree_levelorder - Function goes through a binary tree using the level
 *	order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call each node.
 *
 * Return: void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/*print if the root node*/
	if (tree->parent == NULL)
		func(tree->n);

	/*print the right and left child*/
	if (tree->left)
		func(tree->left->n);
	if (tree->right)
		func(tree->right->n);

	/*traverse the left subtree*/
	binary_tree_levelorder(tree->left, func);

	/*traverse the right subtree*/
	binary_tree_levelorder(tree->right, func);
}
