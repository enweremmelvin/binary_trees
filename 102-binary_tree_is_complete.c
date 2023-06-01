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
 * clear_queue - delete all nodes in the queue
 *
 * @queue: queue to clear
 */

void clear_queue(queue_n *queue)
{
	queue_n *temp;

	if (queue == NULL)
		return;

	temp = queue;

	while (queue != NULL)
	{
		queue = temp->next;
		free(temp);
		temp = queue;
	}
}


/**
 * binary_tree_is_complete - check if a binary tree is complete
 *
 * @tree: binary tree to be checked
 *
 * Return: 1 if complete ; 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int flag = 0;
	queue_n *queue;
	binary_tree_t *tree_node, *node;

	if (tree == NULL)
		return (0);
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

		if ((flag == 1) && ((tree_node->left != NULL) ||
				    (tree_node->right != NULL)))
		{
			clear_queue(queue);
			return (0);
		}
		if ((tree_node->left == NULL) && (tree_node->right != NULL))
		{
			clear_queue(queue);
			return (0);
		}
		if (tree_node->left != NULL)
			add_node(queue, tree_node->left);
		if ((tree_node->right != NULL) && (flag == 0))
			add_node(queue, tree_node->right);
		if ((tree_node->left == NULL) || (tree_node->right == NULL))
			flag = 1;
		queue = pop_node(queue);
	}

	return (flag);
}
