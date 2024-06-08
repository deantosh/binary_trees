#include "binary_trees.h"

/**
 * bst_search - Function searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search in the tree.
 *
 * Return: node with the value (success) or NULL (fails).
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (!tree)
		return (NULL);

	/*if value is found*/
	if (tree->n == value)
		return ((bst_t *)tree);

	/*if value < current node -- traverse left subtree*/
	if ((tree->n > value) && tree->left)
		return (bst_search(tree->left, value));

	/*if value > current node -- traverse right subtree*/
	if ((tree->n < value) && tree->right)
		return (bst_search(tree->right, value));

	return (NULL);
}
