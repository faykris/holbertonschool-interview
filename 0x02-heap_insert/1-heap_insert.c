#include "binary_trees.h"

/**
 * size - Calculate the size of a binary tree
 * @tree: Pointer to the root node of binary tree
 *
 * Return: Size in number value, 0 if tree is NULL
 **/
size_t size(const binary_tree_t *tree)
{
	size_t t_size = 0;

	if (!tree)
		return (0);
	if (tree->left)
		t_size = t_size + size(tree->left);
	if (tree->right)
		t_size = t_size + size(tree->right);
	t_size += 1;
	return (t_size);
}

/**
 * is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of binary tree
 *
 * Return: 1 if binary tree is perfect, othewise 0
 */
int is_perfect(const binary_tree_t *tree)
{
	int l_size, r_size;

	if (!tree)
		return (0);
	l_size = size(tree->left);
	r_size = size(tree->right);
	if (l_size == r_size)
		return (1);
	return (0);
}

/**
 * swap - Change nodes values, child to parent
 * @node1: Node 1 tree to change
 * @node2: Node 2 tree to change
 *
 * Return: New position of node greater
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
	else if (is_perfect(*root) || !is_perfect((*root)->left))
	{
		if ((*root)->left)
			temp = heap_insert(&((*root))->left, value);
		else
		{
			temp = binary_tree_node(*root, value);
			(*root)->left = temp;
		}
	}
	else
	{
		if ((*root)->right)
			temp = heap_insert(&((*root)->right), value);
		else
		{
			temp = binary_tree_node(*root, value);
			(*root)->right = temp;
		}
	}
	if (temp->parent && temp->n > temp->parent->n)
		temp = swap(temp, temp->parent);
	return (temp);
}
