#include "binary_trees.h"

/**
 * binary_tree_inorder - Function goes through the binary tree using
 *		in-order traversal.
 * @tree: A pointer to the root node of the tree to traverse
 * @func: A pointer to a function to call each node. The value in the
 *		node must be passed as a parameter to this function.
 *
 * Return: void.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/*traverse the left subtree*/
	binary_tree_inorder(tree->left, func);

	/*print the current node*/
	func(tree->n);

	/*traverse the right subtree*/
	binary_tree_inorder(tree->right, func);
}
