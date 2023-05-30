#include "binary_trees.h"

/**
 * binary_tree_sibling - find the sibling of a node in a binary tree
 *
 * @node: node whose sibling is to be found
 *
 * Return: NULL if: node or parent is null | node has no sibling
 *         otherwise, pointer to sibling node
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if ((node == NULL) || (node->parent == NULL))
		return (NULL);

	if (node->parent->left == node)
	{
		if (node->parent->right != NULL)
			return (node->parent->right);
	}
	else if (node->parent->right == node)
	{
		if (node->parent->left != NULL)
			return (node->parent->left);
	}

	return (NULL);
}
