#include "binary_trees.h"

/**
 * binary_tree_balance - find the balance factor of a binary tree node
 *
 * @tree: pointer to node to be checked
 *
 * Return: 2 if its a balanced node or -1 if it has one child or 0 otherwise
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	binary_tree_t *left_child;
	binary_tree_t *right_child;

	if (tree == NULL)
		return (0);

	left_child = tree->left;
	right_child = tree->right;

	if ((left_child != NULL) && (right_child != NULL))
		return (2);
	else if ((left_child != NULL) || (right_child != NULL))
		return (-1);

	return (0);
}
