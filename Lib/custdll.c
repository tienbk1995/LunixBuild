#include "custdll.h"
#include <stdio.h>
#include <stdlib.h>
void push (node **head, int new_data){
    node *new_node = (node*)malloc(1*sizeof(node));
    new_node->data = new_data;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) (*head)->prev = new_node;
    *head = new_node;
}

void printList (node *head){
    
    node *last;
    printf ("Traverse in forward direction\n");
    while (head != NULL){
        printf (" %d ", head->data);
        last = head;
        head = head->next;
    }
    printf ("\n");
    printf ("Traverse in backward direction\n");
    while (last != NULL){
        printf (" %d ", last->data);
        last = last->prev;
    }
    printf ("\n");
}