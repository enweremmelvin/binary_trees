#include "binary_trees.h"

/**
 * binary_tree_depth - find the depth of a node in a binary tree
 *
 * @tree: tree to find it's depth
 *
 * Return: depth of linked list ; otherwise 0 if tree is NULL
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int depth = 1;

	if (tree == NULL)
		return (0);

	if (tree->parent != NULL)
		depth += binary_tree_depth(tree->parent);
	else
		return (depth - 1);

	return (depth);
}
