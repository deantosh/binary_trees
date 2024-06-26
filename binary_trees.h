#ifndef BINARY_TREES_H
#define BINARY_TREES_H

/*include files*/
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s bst_t;
typedef struct binary_tree_s avl_t;

/*Function Prototypes*/
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
void binary_tree_print(const binary_tree_t *tree);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int tree_height(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
									 const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_complete(const binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(const bst_t *tree, int value);
int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);

/* HELPER FUNCTION*/
int full_check_height(const binary_tree_t *tree, int depth, int *leaf_level);
int number_of_nodes(const binary_tree_t *node);
int tree_is_complete(const binary_tree_t *tree, int index, int node_count);
void process_level(const binary_tree_t *tree, int level, void (*func)(int));
int b_height(const binary_tree_t *tree);
int valid_bst_helper(const binary_tree_t *tree, const binary_tree_t *min,
		     const binary_tree_t *max);
bst_t *find_leaf_node(bst_t *curr, int value);
int is_balance_factor_1_or_0(const binary_tree_t *tree);
avl_t *insert_new_node(avl_t *curr, int value);
void balance_tree(avl_t **tree, avl_t *curr);
avl_t *find_node_to_delete(avl_t *curr, int value);
avl_t *find_min(avl_t *node);
avl_t *rebalance_avl_tree(avl_t *root, avl_t *curr);
avl_t *delete_node(avl_t **root, avl_t *node);

#endif /*BINARY_TREES_H*/
