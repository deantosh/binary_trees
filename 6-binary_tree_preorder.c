#include "binary_trees.h"

/**
 * binary_tree_preorder - function to traverse BT
 *	using pre-order traversal.
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 *
 * Return: if tree or functions is null, do nothing
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/*print the node value*/
	func(tree->n);

	/*traverse the left subtree*/
	binary_tree_preorder(tree->left, func);
	/*traverse the right subtree*/
	binary_tree_preorder(tree->right, func);
}
