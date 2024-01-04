#include "binary_trees.h"

/**
 * binary_tree_node - Creates a binary tree node
 * @parent: A pointer to the parent node of the node to be created.
 * @value: The new node value.
 *
 * Return: new node (success) or NULL (fails).
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	/*allocate memory for new child*/
	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);

	/*create the new node*/
	new->parent = parent;
	new->n = value;
	new->left = NULL;
	new->right = NULL;

	return (new);
}
