#include "binary_trees.h"

/**
 * avl_insert - Function inserts a value in an AVL tree.
 * @tree: A double pointer to the root node os the AVL tree.
 * @value: The value of the node to be inserted to the tree.
 *
 * Return: new node (success) or NULL (fails).
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *curr, *new_node, *leaf_node, *unbalanced_node;
	int balance_factor;

	/*set the current pointer position*/
	curr = (*tree);
	/*If tree is empty - create the new node*/
	if (!curr)
	{
		new_node = binary_tree_node(curr, value);
		if (!new_node)
			return (NULL);
		*tree = new_node;  /*move head to new node*/
		return (new_node);
	}
	/*Find the leaf_node*/
	leaf_node = find_leaf_node(curr, value);
	if (!leaf_node)
		return (NULL);
	/*create new node*/
	new_node = binary_tree_node(leaf_node, value);
	if (!new_node)
		return (NULL);
	/*select which child is the new node- left or right*/
	if (value < leaf_node->n)
		leaf_node->left = new_node;
	if (value > leaf_node->n)
		leaf_node->right = new_node;
	/*Handle AVL tree not balance*/
	unbalanced_node = find_unbalanced_node(curr);
	balance_factor = binary_tree_balance(unbalanced_node);
	/*If: +2 - rotate right to balance*/
	if (balance_factor == 2)
	{
		if (binary_tree_balance(unbalanced_node->left) == -1)
			binary_tree_rotate_left(unbalanced_node->left);
		binary_tree_rotate_right(unbalanced_node);
	}
	/*If: -2 - rotate left to balance*/
	if (balance_factor == -2)
	{
		if (binary_tree_balance(unbalanced_node->right) == 1)
			binary_tree_rotate_right(unbalanced_node->right);
		binary_tree_rotate_left(unbalanced_node);
	}
	return (new_node);
}

/**
 * find_leaf_node - Function finds the leaf node to add the
 *	new node at its end.
 * @curr: A pointer to the root node to the tree to insert.
 * @value: The value of the node to insert to tree.
 *
 * Return: leaf node (success) or NULL (fails).
 */
avl_t *find_leaf_node(avl_t *curr, int value)
{
	/*Base case: terminates the loop*/
	if (!curr)
		return (NULL);

	/*Choose the subtree to traverse: to add new node*/
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

/**
 * find_unbalanced_node - Function finds the node that is unbalanced.
 * @tree: A pointer to the root node of the tree to search.
 *
 * Return: unbalanced node (success) or NULL (fails).
 */
avl_t *find_unbalanced_node(avl_t *tree)
{
	avl_t *left_unbalanced, *right_unbalanced;
	int balance_factor;

	if (!tree)
		return (NULL);

	/*If node is unbalanced*/
	balance_factor = binary_tree_balance(tree);
	if (balance_factor == 2  || balance_factor == -2)
		return (tree);

	/*Traverse the right and left subtree*/
	right_unbalanced = find_unbalanced_node(tree->right);
	if (right_unbalanced)
		return (right_unbalanced);
	left_unbalanced = find_unbalanced_node(tree->left);
	if (left_unbalanced)
		return (left_unbalanced);

	return (NULL);
}
