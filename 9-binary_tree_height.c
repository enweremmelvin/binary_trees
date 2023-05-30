#include "binary_trees.h"

/**
 * binary_tree_height - compute the height of a binary tree
 *
 * @tree: binary tree whose height is to be gotten
 *
 * Return: height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int height = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height += binary_tree_height(tree->left);
	else if (tree->right != NULL)
		height += binary_tree_height(tree->right);

	if ((tree->left == NULL) && (tree->right == NULL))
		height -= 1;

	return (height);
}
