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

	if ((tree->left == NULL) || (tree->right == NULL))
		height = 2;

	if ((tree->left != NULL) || (tree->right != NULL))
	{
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);

		if (l_height > r_height)
			height += l_height;
		else if (r_height > l_height)
			height += r_height;
		else
			height += r_height;

		if (!((tree->left != NULL) && (tree->right != NULL)))
			height -= 1;
	}

	if ((tree->left == NULL) && (tree->right == NULL))
		height -= 1;

	return (height);
}

/**
 * binary_tree_balance - find the balance factor of a binary tree node
 *
 * @tree: pointer to node to be checked
 *
 * Return: 2 if its a balanced node or -1 if it has one child or 0 otherwise
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
