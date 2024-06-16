#include "binary_trees.h"

/**
 * avl_remove - Function removes a node from an AVL tree.
 * @root: A pointer to the root node of the tree to remove the node.
 * @value: The value to remove in the tree.
 *
 * Return: root (success) or NULL (fails).
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *parent, *node, *child;

	if (!root)
		return (NULL);
	node = find_node_to_delete(root, value);
	if (node)
	{
		parent = node->parent;
		if (!node->left && !node->right)
		{
			if (parent->n > node->n)
				parent->left = NULL;
			else
				parent->right = NULL;
			free(node);
		}
		else if (node->left && node->right)
		{
			parent = delete_node(&root, node);
		}
		else
		{
			if (node->left)
				child = node->left;
			else
				child = node->right;
			if (parent)
			{
				if (parent->n > node->n)
					parent->left = child;
				else
					parent->right = child;
			}
			child->parent = parent;
			if (!child->parent)
				root = child;
			free(node);  /*delete the node*/
		}
	}
	return (rebalance_avl_tree(root, parent));
}

/**
 * delete_node - Function deletes node from the AVL tree.
 * @root: A double pointer to the root node of the AVL tree.
 * @node: A pointer to the to be deleted from AVL tree.
 *
 * Return: parent of deleted node (always).
 */
avl_t *delete_node(avl_t **root, avl_t *node)
{
	avl_t *parent, *successor_node, *successor_parent = NULL;

	parent = node->parent;
	/*find the successor node*/
	successor_node = find_min(node->right);
	if (successor_node->parent != node)
		successor_parent = successor_node->parent;
	/*handle successor node*/
	if (parent)
	{
		if (parent->left == node)
			parent->left = successor_node;
		else
			parent->right = successor_node;
	}
	else
	{
		*root = successor_node;
	}
	successor_node->parent = parent;
	if (node->right != successor_node)
		successor_node->right = node->right;
	else
		successor_node->right = NULL;
	successor_node->left = node->left;
	if (node->left)
		node->left->parent = successor_node;
	if (node->right != successor_node)
		node->right->parent = successor_node;
	if (successor_parent)
	{
		if (successor_parent->left == successor_node)
			successor_parent->left = NULL;
		if (successor_parent->right == successor_node)
			successor_parent->right = NULL;
	}
	free(node);
	if (successor_parent)
		return (successor_parent);
	return (successor_node);
}

/**
 * find_node_to_delete - Function finds the node to delete from the AVL tree.
 * @curr: A pointer to the current node of the tree.
 * @value: The value to remove in the tree.
 *
 * Return: node to delete (if found) or NULL (if not found).
 */
avl_t *find_node_to_delete(avl_t *curr, int value)
{
	avl_t *node;

	/*Base case: terminate the loop*/
	if (!curr)
		return (NULL);

	if (curr->n == value)
		return (curr);

	/*traverse the AVL tree*/
	if (curr->left || curr->right)
	{
		if (value < curr->n)
		{
			/*traverse left*/
			node =  find_node_to_delete(curr->left, value);
			if (node)
				return (node);
		}
		else
		{
			/*traverse right*/
			node = find_node_to_delete(curr->right, value);
			if (node)
				return (node);
		}
	}

	return (NULL);
}

/**
 * find_min -  Function finds the node with minimum value in a subtree.
 * @node: A pointer to the root node of the subtree to search.
 *
 * Return: node with minimum value (always).
 */
avl_t *find_min(avl_t *node)
{
	if (node->left)
		return (find_min(node->left));
	return (node);
}

/**
 * rebalance_avl_tree - Function balances the AVL tree after deleting a node.
 * @root: A pointer to the root node of the tree to balance.
 * @curr: A pointer to the successor node parent.
 *
 * Return: root (success) or NULL (fails).
 */
avl_t *rebalance_avl_tree(avl_t *root, avl_t *curr)
{
	avl_t *unbalanced_node_parent = NULL, *r_node = NULL;
	int balance_factor;

	/*get the node to check if balance*/
	while (curr)
	{
		balance_factor = binary_tree_balance(curr);
		/*left heavy*/
		if (balance_factor > 1)
		{
			unbalanced_node_parent = curr->parent;
			if (binary_tree_balance(curr->left) < 0)
				binary_tree_rotate_left(curr->left);
			r_node = binary_tree_rotate_right(curr);
		}
		/*right heavy*/
		if (balance_factor < -1)
		{
			unbalanced_node_parent = curr->parent;
			if (binary_tree_balance(curr->left) > 0)
				binary_tree_rotate_right(curr->right);
			r_node = binary_tree_rotate_left(curr);
		}
		curr = curr->parent;
	}
	if (unbalanced_node_parent)
	{
		if (unbalanced_node_parent->n > r_node->n)
			unbalanced_node_parent->left = r_node;
		else
			unbalanced_node_parent->right = r_node;
		r_node->parent = unbalanced_node_parent;
	}
	return (root);
}
