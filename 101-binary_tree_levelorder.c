#include <stdlib.h>
#include "binary_trees.h"

/**
 * first_node - return the first node in the queue
 *
 * @queue: queue whose first node is to be gotten
 *
 * Return: pointer to <node> value of queue node
 */

binary_tree_t *first_node(queue_n *queue)
{
	if ((queue == NULL) || (queue->node == NULL))
		return (NULL);

	return (queue->node);
}

/**
 * add_node - add a new node to the end of queue
 *
 * @queue: queue to add a new node to
 * @node: value to add to <node> part of new queue node
 */

void add_node(queue_n *queue, binary_tree_t *node)
{
	queue_n *temp;
	queue_n *new_queue_node;

	if ((queue == NULL) || (node == NULL))
		return;

	temp = queue;

	new_queue_node = malloc(sizeof(queue_n));
	new_queue_node->node = node;
	new_queue_node->next = NULL;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = new_queue_node;
}

/**
 * pop_node - delete the first node in queue
 *
 * @queue: queue to delete node from
 *
 * Return: pointer of new queue head
 */

queue_n *pop_node(queue_n *queue)
{
	queue_n *temp;

	if (queue == NULL)
		return (NULL);

	temp = queue;

	if (temp->node != NULL)
	{
		queue = temp->next;
		free(temp);

		return (queue);
	}

	return (NULL);
}

/**
 * binary_tree_levelorder - print values of a binary tree \
 *                          using the level order traversal
 *
 * @tree: tree whose values are to be printed
 * @func: function to call on each traversal
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_n *queue;
	binary_tree_t *node;
	binary_tree_t *tree_node;

	if ((tree == NULL) || (func == NULL))
		return;

	if (tree->left != NULL)
		node = tree->left->parent;
	else if (tree->right != NULL)
		node = tree->right->parent;

	queue = malloc(sizeof(queue_n));
	queue->node = node;
	queue->next = NULL;

	while (queue != NULL)
	{
		tree_node = first_node(queue);
		func(tree_node->n);

		if (tree_node->left != NULL)
			add_node(queue, tree_node->left);
		if (tree_node->right != NULL)
			add_node(queue, tree_node->right);

		queue = pop_node(queue);
	}
}
