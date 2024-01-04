#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_preorder - Traverses the binary tree using the pre-order method.
 * @tree: A pointer to the root node of the binary tree.
 * @func: A function pointer to call for each node. Value of node passed as a
 *		parameter to function.
 *
 * Return: void.
*/
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/*pass node value to function*/
	func(tree->n);

	/*traverse on the left*/
	binary_tree_preorder(tree->left, func);

	/*traverse on the right*/
	binary_tree_preorder(tree->right, func);
}
