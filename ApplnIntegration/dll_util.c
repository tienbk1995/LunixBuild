#include "dll.h"
#include <stdlib.h>
#include <memory.h>

/*More functions*/
int /*return 0 on success and -1 on failure*/
remove_data_from_dll_by_data_ptr(dll_t *dll, void *data)
{
    if (!dll->head)
        return -1;
    dll_node_t *remove_node = dll->head;

    while (remove_node->data != data && !remove_node)
    {
        remove_node = remove_node->right;
    }
    if (!remove_node)
        return -1;
    remove_node->left->right = remove_node->right;
    remove_node->right->left = remove_node->left;
    free(remove_node);
    return 0;
}

/*return 0 if empty, -1 if not empty*/
int is_dll_empty(dll_t *dll)
{
    if (!dll->head)
        return 0;
    return -1;
}

/* delete all nodes from a dll, but do not free appln data*/
void drain_dll(dll_t *dll)
{
    if (!dll->head)
        return;
    dll_node_t *remove_node = dll->head;
    while (remove_node)
    {
        remove_node = dll->head;
        dll->head = dll->head->right;
        free(remove_node);
    }
    return;
}
