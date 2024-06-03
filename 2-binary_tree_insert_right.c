#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of
 *		another node.
 * @parent: a pointer to the node to insert the right child in.
 * @value: the value to store in the new node.
 *
 * Return: a new_node (success) or NULL (fails).
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *right_child;

	if (!parent)
		return (NULL);

	/*create node*/
	right_child = binary_tree_node(parent, value);
	if (!right_child)
		return (NULL);

	/*handle: if parent -> right child exists*/
	if (parent->right)
	{
		right_child->right = parent->right;
		parent->right->parent = right_child;
	}
	/*create right branch from parent*/
	parent->right = right_child;

	return (right_child);
}
