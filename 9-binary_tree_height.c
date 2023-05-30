#include "binary_trees.h"
#include <stdio.h>

/**
 * get_height - get the height of a binary tree
 *
 * @tree: tree whose height is to be gotten
 *
 * Return: height of tree
 */

size_t get_height(const binary_tree_t *tree)
{
	static size_t height = 1;

	if (tree == NULL)
		return (0);

	if ((tree->left != NULL) || (tree->right != NULL))
		height += 1;

	get_height(tree->left);
	get_height(tree->right);

	return (height);
}


/**
 * binary_tree_height - compute the height of a binary tree
 *
 * @tree: binary tree whose height is to be gotten
 *
 * Return: height of the binary tree
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t ret_val;
	size_t left_height;
	size_t right_height;

	static size_t sub = 1;

	if (tree == NULL)
		return (0);

	left_height = get_height(tree->left);
	right_height = get_height(tree->right);

	if (right_height > 0)
		right_height -= sub;

	sub += 1;

	if (left_height > right_height)
		ret_val = left_height;
	else if (right_height > left_height)
		ret_val = right_height;
	else
		ret_val = left_height;

	return (ret_val);
}
