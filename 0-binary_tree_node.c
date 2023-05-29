#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_node - this function creates a binary tree node
 *
 * @parent: parent of the new node to be created
 * @value: value of node to be created
 *
 * Return: a pointer to the created node or NULL on failure
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	/* return NULL if malloc fails */
	if (new_node == NULL)
		return (NULL);

	/* initialize the values of new_node */
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->parent = parent;

	return (new_node);
}
