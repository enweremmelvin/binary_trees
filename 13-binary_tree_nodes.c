#include "binary_trees.h"

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

	if ((tree->parent == NULL) &&
	    ((tree->right != NULL) || (tree->left == NULL)))
		nodes += 1;

	if (tree->left != NULL)
	{
		nodes += 1;
		binary_tree_nodes(tree->left);
	}

	if (tree->right != NULL)
	{
		nodes += 1;
		binary_tree_nodes(tree->right);
	}

	return (nodes);
}
