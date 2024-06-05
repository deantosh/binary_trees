#include "binary_trees.h"

/**
 * binary_tree_sibling - function that finds the sibling of a node.
 * @node: Pointer to the node to find the sibling.
 *
 * Return: Pointer to the sibling node.
 *	If node is NULL, the parent is NULL, or node has no sibling, return NULL.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (node == NULL || node->parent == NULL)
		return (NULL);

	if (node->parent->left == NULL || node->parent->right == NULL)
		return (NULL);

	if (node->parent->left == node)
		return (node->parent->right);
	else
		return (node->parent->left);
}
