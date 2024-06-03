#include "binary_trees.h"

/**
 * binary_tree_node - Creats a binary tree node.
 * @parent: A pointer to the parent node of the node to create
 * @value: tthe value to put in the new node
 *
 * Return: A pointer to new node (success) or NULL (fails).
 */
binaary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	/*allocate memory*/
	new_node = (binary_tree_t *)malloc(sizeof(binary_tree_t))
	if (new_node == NULL)
		return (NULL);

	/*create new node*/
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}
