#include "custdll.h"
#include <stdio.h>

int main (){
    node *head = NULL;
    push(&head, 10);
    push(&head, 20);
    push(&head, 30);
    printf("Created DLL is: \n");
    printList(head);
}