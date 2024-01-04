#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right child
 *				of another node.
 * @parent: The parent node.
 * @value: The value of the new node.
 *
 * Return: new node (success) or NULL (fails or parent == NULL).
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child;

	/*validate values to func*/
	if (!parent)
		return (NULL);

	/*create new node*/
	new_child = binary_tree_node(parent, value);
	if (!new_child)
		return (NULL);

	if (parent->right)
	{
		new_child->right = parent->right;
		parent->right->parent = new_child;
	}
	parent->right = new_child;

	return (new_child);
}
