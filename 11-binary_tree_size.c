#include "binary_trees.h"

/**
 * binary_tree_size - find the size of a binary tree
 * --- size == all nodes inside the binary tree
 *
 * @tree: binary tree to be traversed
 *
 * Return: size of binary tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	int size = 1;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}
