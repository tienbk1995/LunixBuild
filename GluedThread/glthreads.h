#ifndef __GLTHREADS__
#define __GLTHREADS__

typedef struct glthreads_node 
{
    glthreads_node *left;
    glthreads_node *right;
} glthreads_node_type;

typedef struct glthreads_tree
{
    glthreads_node *head;
    unsigned int offset;
} glthreads_tree_type;

void glthread_add (glthreads_tree_type *lst, glthreads_node_type *node);

void glthread_remove (glthreads_tree_type *lst, glthreads_node_type *node);

void glthread_init_thread (glthreads_tree_type *lst, unsigned int offset);

#define GLTHEAD_INIT_NODE(node) \
    node->left = NULL;          \
    node->right = NULL;

#define ITERATE_THREAD_BEGIN(lst, data_struct, return_node) \
{
    glthreads_node_type *curr_node = NULL, *next_node = NULL; \
    for(curr_node = lst->head; curr_node; curr_node = next_node) { \
        next_node = curr_node->right; \
        return_node = (data_struct *)((char *)(curr_node - lst->offset));
#define ITERATE_THREAD_END }}

