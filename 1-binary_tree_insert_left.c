#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as the left \
 *                           child of given parent node
 *
 * @parent: parent node where \
 *          left child is to be inserted into
 *
 * @value: value of left child to be inserted
 *
 * Return: pointer to newly inserted node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (parent == NULL)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	/*
	 * set left child of parent to new node if parent->left is NULL	\
	 * otherwise, set parent->left as left child of new_node and	\
	 * new_node as left child of parent
	 */
	if (parent->left == NULL)
	{
		parent->left = new_node;
	}
	else
	{
		new_node->left = parent->left;
		parent->left->parent = new_node;
		parent->left = new_node;
	}

	return (new_node);
}
