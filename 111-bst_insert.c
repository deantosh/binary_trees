#include "binary_trees.h"

/**
 * bst_insert - Function inserts a value in a binary search tree.
 * @tree: A double pointer to the root node of the BST to insert value.
 * @value: The value to store in the node to be inserted.
 *
 * Return: new node (success) or NULL (fails).
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *leaf_node = NULL, *root = (*tree);

	/*if the tree does not exists*/
	if (!tree)
		return (NULL);

	/*if tree is empty, new node is root*/
	if (!root)
	{
		/*create new node*/
		new_node = binary_tree_node(root, value);
		if (!new_node)
			return (NULL);
		*tree = new_node;  /*assign the new node as root*/
		return (new_node);
	}

	/*find where to add new node*/
	leaf_node = find_leaf_node(root, value);
	/*if duplicate value found*/
	if (!leaf_node)
		return (NULL);

	/*create new node*/
	new_node = binary_tree_node(leaf_node, value);
	if (!new_node)
		return (NULL);

	/*set it as left or right child*/
	if (leaf_node->n > value)
		leaf_node->left = new_node;
	else
		leaf_node->right = new_node;

	return (new_node);
}

/**
 * find_leaf_node - Finds the leaf node to add the new node.
 * @curr: A pointer to the current node at BST.
 * @value: The value to insert to new node.
 *
 * Return: leaf node to add new node (success) or NULL (fails).
 */
bst_t *find_leaf_node(bst_t *curr, int value)
{
	/*Base case: terminates the loop*/
	if (!curr)
		return (NULL);

	/*Choose the subtree: to add new node*/
	if (value < curr->n)
	{
		if (curr->left)
			return (find_leaf_node(curr->left, value));
		else
			return (curr);
	}
	else if (value > curr->n)
	{
		if (curr->right)
			return (find_leaf_node(curr->right, value));
		else
			return (curr);
	}

	return (NULL);
}
