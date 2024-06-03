#include "binary_trees.h"

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: a pointer to the root node of the tree to delete
 *
 * Return: void.
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;

	/*delete left subtree*/
	binary_tree_delete(tree->left);

	/*delete right subtree*/
	binary_tree_delete(tree->right);

	/*free current node*/
	free(tree);
}
