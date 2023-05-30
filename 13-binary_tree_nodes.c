#include "binary_trees.h"


/**
 * count_nodes - count non-leaf nodes in a binary tree
 *
 * @tree: binary tree whose nodes are to be counted
 * @nodes: variable with value of non-leaf nodes
 *
 * Return: number of non-leaf nodes in a binary tree
 */

int count_nodes(const binary_tree_t *tree, int *nodes)
{
	if (tree == NULL)
		return (0);

	if (tree != NULL)
		*nodes += 1;

	if ((tree->left == NULL) && (tree->right == NULL))
		*nodes -= 1;

	count_nodes(tree->left, nodes);
	count_nodes(tree->right, nodes);

	return (*nodes);
}

/**
 * binary_tree_nodes - count nodes with one \
 *                     or more child(ren) in a binary tree
 *
 * @tree: tree whose nodes are to be counted
 *
 * Return: 0 if tree is NULL ; otherwise number of counted nodes
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	int nodes = 0;

	if (tree == NULL)
		return (0);

	nodes = count_nodes(tree, &nodes);

	return (nodes);
}
