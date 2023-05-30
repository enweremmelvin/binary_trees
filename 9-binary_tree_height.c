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
	int l_height;
	int r_height;
	int height = 1;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
	{
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);

		if (l_height > r_height)
			height += l_height;
		else if (r_height > l_height)
			height += r_height;
		else
			height += r_height;
	}
	else if (tree->right != NULL)
	{
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);

		if (l_height > r_height)
			height += l_height;
		else if (r_height > l_height)
			height += r_height;
		else
			height += r_height;
	}

	if ((tree->left == NULL) && (tree->right == NULL))
		height -= 1;

	return (height);
}
