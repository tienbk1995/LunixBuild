#include "glthreads.h"
#include <stdlib.h>
#include <stdio.h>

// Private APIs
static void _glthreads_add_next(glthreads_node_type *cur_node, glthreads_node_type *new_node) // To insert new node right after current node
{
    if (!cur_node->right) // current node is the last node (tail)
    {
        cur_node->right = new_node;
        new_node->left = cur_node;
        return;
    }
    // Insert new node after current node and before current node's right
    glthreads_node_type *temp_node = cur_node->right;
    new_node->left = cur_node;
    new_node->right = temp_node;
    cur_node->right = new_node;
    temp_node->left = new_node;
    return;
}

static void _remove_node(glthreads_tree_type *lst, glthreads_node_type *node)
{
    if (!node->left && node->right)
    {
        // Node is head and not only 1
        printf("HEAD AND\n");
        lst->head = node->right;
        node->right->left = NULL;
        node->right = NULL;
        return;
    }
    if (!node->right && node->left)
    {
        printf("TAIL AND\n");
        // Node is tail and not only 1
        node->left->right = NULL;
        node->left = NULL;
        return;
    }

    if (lst->head == node)
    { // Node is head and only
        printf("ONLY HEAD\n");
        lst->head = NULL;
        node = NULL;
        return;
    }
    
    // Node is surrounded by other nodes
    printf("SURROUNDED\n");
    node->left->right = node->right;
    node->right->left = node->left;
    node->left = NULL;
    node->right = NULL;
    return;
}
// Public APIs
void glthread_init_thread(glthreads_tree_type *lst, unsigned int offset)
{
    lst->head = NULL;
    lst->offset = offset;
}

void glthread_add(glthreads_tree_type *lst, glthreads_node_type *node)
{
    node->left = NULL;
    node->right = NULL;
    if (!lst->head)
    {
        lst->head = node;
        return;
    }
    glthreads_node_type *head = lst->head;
    // Insertn new node before the head
    _glthreads_add_next(node, head);
    lst->head = node; // Assign new head to new node
}

void glthread_remove(glthreads_tree_type *lst, glthreads_node_type *node)
{
    _remove_node(lst, node);
}
