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
	avl_t *new_node;

	/*If tree is empty - add new_node, make it root of tree*/
	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		if (!new_node)
			return (NULL);
		*tree = new_node;  /*move head to new node*/
		return (new_node);
	}
	/*If tree not empty: add new_node*/
	new_node = insert_new_node(*tree, value);

	/*If tree unbalanced: balance it*/
	balance_tree(tree, new_node);

	return (new_node);
}

/**
 * insert_new_node - Function inserts a new node in the AVL tree
 * @curr: A pointer to the current node of the tree.
 * @value: The value of the node to insert to tree.
 *
 * Return: new_node (success) or NULL (fails).
 */
avl_t *insert_new_node(avl_t *curr, int value)
{
	avl_t *new_node;

	/*Base case: terminates the loop*/
	if (!curr)
		return (NULL);

	/*Choose the subtree to traverse: to add new node*/
	if (value < curr->n)
	{
		if (curr->left)
		{
			return (insert_new_node(curr->left, value));
		}
		else
		{
			/*create the new node*/
			new_node = binary_tree_node(curr, value);
			if (!new_node)
				return (NULL);
			curr->left = new_node;
			return (new_node);
		}
	}
	else if (value > curr->n)
	{
		if (curr->right)
		{
			return insert_new_node(curr->right, value);
		}
		else
		{
			/*create the new node*/
			new_node = binary_tree_node(curr, value);
			if (!new_node)
				return (NULL);
			curr->right = new_node;
			return (new_node);
		}
	}

	return (NULL);
}

/**
 * balance_tree - Function balances the AVL tree after inserting a new node.
 * @tree: A double pointer to the AVL tree.
 * @curr: A pointer to the inserted node.
 *
 * Return: void.
 */
void balance_tree(avl_t **tree, avl_t *curr)
{
	avl_t *parent;
	int balance_factor;

	while (curr)
	{
		balance_factor = binary_tree_balance(curr);

		if (balance_factor > 1)
		{
			if (binary_tree_balance(curr->left) < 0)
				curr->left = binary_tree_rotate_left(curr->left);
			curr = binary_tree_rotate_right(curr);
		}
		else if (balance_factor < -1)
		{
			if (binary_tree_balance(curr->right) > 0)
				curr->right = binary_tree_rotate_right(curr->right);
			curr = binary_tree_rotate_left(curr);
		}

		parent = curr->parent;
		if (!parent)
			*tree = curr;  /*Handle new root*/
		curr = parent;
	}
}

