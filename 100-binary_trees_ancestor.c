#include "binary_trees.h"

/**
 * binary_trees_ancestor - Function finds the lowest common ancestor
 *	of two nodes.
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: ancestor node (success) or NULL (fails).
 */
binary_tree_t *binary_trees_ancestor(
				     const binary_tree_t *first,
				     const binary_tree_t *second)
{
	const binary_tree_t *ptr = NULL;

	if (!first || !second)
		return (NULL);

	while (first)
	{
		/*reset value of second node*/
		ptr = second;
		while (ptr)
		{
			/*find common ancestor*/
			if (first->n == ptr->n)
				return ((binary_tree_t *)first);
			ptr = ptr->parent;
		}
		first = first->parent;
	}
	return (NULL);
}
