#include "binary_trees.h"

/**
 * check_nodes - check if all child nodes (except leaf nodes) have two children
 *
 * @tree: binary tree to be checked
 * @full_node: variable to increment when a non-full node is found
 */

void check_nodes(const binary_tree_t *tree, int *full_node)
{
	if (tree == NULL)
		return;

	if ((tree->left == NULL) || (tree->right == NULL))
		*full_node += 1;
	if ((tree->left == NULL) && (tree->right == NULL))
		*full_node -= 1;

	check_nodes(tree->left, full_node);
	check_nodes(tree->right, full_node);
}

/**
 * binary_tree_is_full - check if a supplied binary tree is full
 *
 * @tree: binary tree to be checked
 *
 * Return: 0 if not full ; 1 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int full = 0;
	int full_node = 0;

	if (tree == NULL)
		return (0);

	check_nodes(tree, &full);
	full_node = full;
	full = 0;

	if (full_node > 0)
		return (0);

	return (1);
}
