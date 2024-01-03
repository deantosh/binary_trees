#include "binary_trees.h"

/**
 * binary_tree_insert_left - Inserts a node as the left child of another node.
 * @parent: The parent node.
 * @value: The value of the new node.
 *
 * Return: new node (success) or NULL (fails or parent == NULL).
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_child, *old_child;

	/*validate values to func*/
	if (!parent)
		return (NULL);

	/*allocate mem for new child*/
	new_child = malloc(sizeof(binary_tree_t));
	if (!new_child)
		return (NULL);

	old_child = parent->left;
	if (old_child)
	{
		new_child->left = old_child;
		old_child->parent = new_child;
	}

	parent->left = new_child;
	new_child->parent = parent;
	new_child->n = value;

	return (new_child);
}
