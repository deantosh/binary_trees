#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes the binary tree.
 * @tree: The binary tree to delete.
 *
 * Return: void.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/*using the postorder traversal*/
	binary_tree_delete(tree->left);
	binary_tree_delete(tree->right);

	/*delete node*/
	free(tree);
}
