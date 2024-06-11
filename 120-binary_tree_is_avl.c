#include "binary_trees.h"

/**
 * binary_tree_is_avl - Functions checks if a binary tree is a valid AVL Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 (true) or 0 (false).
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int bst_value;

	if (!tree)
		return (0);

	/*check if it is a BST*/
	bst_value = valid_bst_helper(tree, NULL, NULL);
	if (bst_value == 0)
		return (0);

	/*check the balance factor*/
	return (is_balance_factor_1_or_0(tree));
}

/**
 * valid_bst_helper - Function checks if a binary tree is BST.
 * @tree: A pointer to the root node of the tree to check.
 * @min: A pointer to the min value to compare with.
 * @max: A pointer to the max value to compare with.
 *
 * Return: 1 (true) or 0 (false).
 */
int valid_bst_helper(const binary_tree_t *tree, const binary_tree_t *min,
		  const binary_tree_t *max)
{
	/*Base case: if empty or leaf node*/
	if (!tree)
		return (1);

	/*Constraint: max*/
	if (max != NULL && tree->n >= max->n)
		return (0);
	/*Constraint: min*/
	if (min != NULL && tree->n <= min->n)
		return (0);

	return (valid_bst_helper(tree->left, min, tree) &&
		valid_bst_helper(tree->right, tree, max));
}

/**
 * is_balance_factor_1_or_0 - Function checks each node has a balance
 *	factor within (-1, 0, 1).
 * @tree: A pointer to the root nodes of the tree to measure the
 *	balance factor.
 *
 * Return: 1 (true) or 0 (false).
 */
int is_balance_factor_1_or_0(const binary_tree_t *tree)
{
	int b_factor;

	if (!tree)
		return (1);

	b_factor = (binary_tree_balance(tree));
	if (b_factor < -1 || b_factor > 1)
		return (0);

	/*check both the left and right subtree*/
	return (is_balance_factor_1_or_0(tree->left) &&
		is_balance_factor_1_or_0(tree->right));
}

/**
 * binary_tree_balance - Function measures the balance factor of a
 *		binary tree.
 * @tree: A pointer to the root nodes of the tree to measure the
 *	balance factor.
 *
 * Return: balance factor (success) or 0 (fails).
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	/*get subtrees height*/
	if (tree->left)
		left_height = tree_height(tree->left) + 1;
	if (tree->right)
		right_height = tree_height(tree->right) + 1;

	/*get the balance factor*/
	return (left_height - right_height);
}


/**
 * tree_height - Function gets the height of a tree.
 * @tree: A pointer to the root node of the tree to find height.
 *
 * Return: height(always).
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (!tree)
		return (0);

	/*traverse the left subtree*/
	if (tree->left)
		left_height = tree_height(tree->left) + 1;

	/*traverse the right subtree*/
	if (tree->right)
		right_height = tree_height(tree->right) + 1;

	/*return the maximum height*/
	return (left_height > right_height ? left_height : right_height);
}
