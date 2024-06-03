#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left-child of
 *		another node.
 * @parent: a pointer to the node to insert the left-child in
 * @value: the valuee to store in the new node
 *
 * Return: A pointer to the new node (success) or NULL (fails).
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_node;

	if (parent == NULL)
		return (NULL);

	/*create node*/
	left_node = binary_tree_node(parent, value);
	if (left_node == NULL)
		return (NULL);

	/*handle already existing parent -> left node*/
	if (parent->left)
	{
		left_node->left = parent->left;
		parent->left->parent = left_node;
	}
	/*create branch to the left node*/
	parent->left = left_node;

	return (left_node);
}
