#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_postorder - Traverses through a binary tree using
 *                              the post-order method.
 * @tree: A pointer to the root node of tree to traverse.
 * @func: A function pointer to the function to print node value.
 *
 * Return: void.
*/
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	/*traverse on the left*/
	binary_tree_postorder(tree->left, func);

	/*traverse on the right*/
	binary_tree_postorder(tree->right, func);

    /*print the node value*/
	func(tree->n);
}
