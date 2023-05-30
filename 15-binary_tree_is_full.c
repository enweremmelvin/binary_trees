#include "binary_trees.h"
#include <stdio.h>

/**
 * binary_tree_is_full - check if a supplied binary tree is full
 *
 * @tree: binary tree to be checked
 *
 * Return: 0 if not full ; 1 otherwise
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	static int full = 1;

	if (tree == NULL)
		return (0);

	if (full > 1)
	{
		full = 1;
		return (1);
	}

	binary_tree_is_full(tree->left);
	binary_tree_is_full(tree->right);

	if ((tree->left == NULL) || (tree->right == NULL))
		full += 1;

	if ((tree->left == NULL) && (tree->right == NULL))
		full -= 1;

	return (0);
}
