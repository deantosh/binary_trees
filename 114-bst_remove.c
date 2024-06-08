#include "binary_trees.h"

/**
 * bst_min_value_node - Finds the node with the minimum value in a BST.
 * @node: Pointer to the root node of the tree.
 *
 * Return: Pointer to the node with the minimum value.
 */
bst_t *bst_min_value_node(bst_t *node)
{
	bst_t *current = node;

	/* finds the leftmost leaf */
	while (current && current->left != NULL)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree.
 * @root: Pointer to the root node of the tree.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of
 *	the tree after removing the desired value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	/* Traverse the tree to find the node to remove */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{

		/* checks if node has one or no child */
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);

			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);

			return (temp);
		}

		/* nodes with 2 child */
		bst_t *temp = bst_min_value_node(root->right);

		/* Copy the inorder successor's content to temp->n */
		root->n = temp->n;

		/* remove the inorder successor */
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
