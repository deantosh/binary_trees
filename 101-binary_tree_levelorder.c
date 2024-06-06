#include "binary_trees.h"

/**
 * binary_tree_levelorder - Function goes through a binary tree using
 *	the level order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call each node.
 *
 * Return: void.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int i, height = 0;

	if (!tree || !func)
		return;

	/*get height of the binary tree*/
	height = tree_height(tree);

	/*traverse the tree levels*/
	for (i = 1; i < height; i++)
	{
		/*print nodes on that tree from left to right*/
		process_level(tree, i, func);
	}
}

/**
 * process_level - Function traverses each tree level and print nodes
 *	from left to right.
 * @tree: The tree to traverse.
 * @level: The level to process.
 * @func: The function to print the values of nodes in that level.
 *
 * Return: void.
 */
void process_level(const binary_tree_t *tree, int level, void(*func)(int))
{
	if (!tree || !func)
		return;

	if (level == 1)
	{
		/*print node value*/
		func(tree->n);
	}
	else if (level > 1)
	{
		/*traverse the left subtree*/
		process_level(tree->left, level - 1, func);
		/*traverser the right subtree*/
		process_level(tree->right, level - 1, func);
	}
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
