#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_inorder - Traverses through a binary tree using the
 *			in-order method.
 * @tree: A pointer to the root node of tree to traverse.
 * @func: A function pointer to the function to print node value.
 *
 * Return: void.
*/
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/*traverse on the left*/
	binary_tree_inorder(tree->left, func);

	/*print the node value*/
	func(tree->n);

	/*traverse on the right*/
	binary_tree_inorder(tree->right, func);
}
