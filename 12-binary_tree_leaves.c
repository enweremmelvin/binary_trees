#include "binary_trees.h"

/**
 * binary_tree_leaves - count the leaves in a binary tree
 *
 * @tree: root of tree whose leaves are to be counted
 *
 * Return: 0 if tree is NULL ; otherwise return number of leaves
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	int leaf = 0;

	if (tree == NULL)
		return (0);

	leaf += binary_tree_leaves(tree->left);
	leaf += binary_tree_leaves(tree->right);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (1);

	return (leaf);
}
