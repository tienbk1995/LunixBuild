#ifndef __GLTHREADS__
#define __GLTHREADS__

typedef struct glthreads_node
{
    struct glthreads_node *left;
    struct glthreads_node *right;
} glthreads_node_type;

typedef struct glthreads_tree
{
    struct glthreads_node *head;
    unsigned int offset;
} glthreads_tree_type;

void glthread_init_thread(glthreads_tree_type *lst, unsigned int offset);

void glthread_add(glthreads_tree_type *lst, glthreads_node_type *node);

void glthread_remove(glthreads_tree_type *lst, glthreads_node_type *node);

#define GLTHEAD_INIT_NODE(node) \
    node->left = NULL;          \
    node->right = NULL;

#define ITERATE_THREAD_BEGIN(lst, data_struct, return_node)         \
{                                                                   \
    glthreads_node_type *_curr_node = NULL;                         \
    glthreads_node_type *_next_node = NULL;                         \
    for(_curr_node = lst->head; _curr_node; _curr_node = _next_node){ \
        _next_node = _curr_node->right;                                  \
        return_node = (data_struct *)((char *)_curr_node - lst->offset);
#define ITERATE_THREAD_END }}

#define offsetof(struct_name, field_name)   \
    ((unsigned int)&((struct_name *)0)->field_name)
    
#endif /* ITERATE_THREAD_*/
