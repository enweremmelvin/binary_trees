#include "binary_trees.h"

/**
 * binary_tree_uncle - find the uncle node of a node in a binary tree
 *
 * @node: node whose uncle is to be found
 *
 * Return: NULL if (node is null, parent is null, parent of parent is null,
 *         no uncle found for node), otherwise return uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if ((node == NULL) || (node->parent == NULL)
	    || (node->parent->parent == NULL))
		return (NULL);

	if (node->parent->parent->left == node->parent)
	{
		if (node->parent->parent->right != NULL)
			return (node->parent->parent->right);
	}
	else if (node->parent->parent->right == node->parent)
	{
		if (node->parent->parent->left != NULL)
			return (node->parent->parent->left);
	}

	return (NULL);
}
