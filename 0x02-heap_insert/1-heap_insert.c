#include "binary_trees.h"

/**
 * binary_tree_is_root - checks if a given node is a root
 * @node: node tree to check
 *
 * Return: 1 if node is a root, otherwise 0
 */
int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->parent == NULL)
	{
		return (1);
	}

	return (0);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: node tree to check
 *
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}

	if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}

/**
 * swap - change node values
 * @node1: node 1 tree to change
 * @node2: node 2 tree to change
 *
 * Return: new position of node greater
 */
heap_t *swap(heap_t *node1, heap_t *node2)
{
	int num = node1->n;

	node1->n = node2->n;
	node2->n = num;

	return (node2);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 *
 * @root: Double pointer to the root node of the Heap
 * @value: The value to store in the node to be inserted
 *
 * Return: pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *temp;

	if (!*root)
		temp = (*root = binary_tree_node(*root, value));
	else if (!(*root)->left)
		temp = ((*root)->left = binary_tree_node(*root, value));
	else if (!(*root)->right)
		temp = ((*root)->right = binary_tree_node(*root, value));
	else
	{
		temp = *root;
		temp = heap_insert(&temp->left, value);
		if (!temp)
			temp = heap_insert(&temp->right, value);
	}
	if (temp->parent && temp->n > temp->parent->n)
		temp = swap(temp, temp->parent);
	return (temp);
}
