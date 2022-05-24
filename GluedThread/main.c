#include <stdio.h>
#include <stdlib.h>
#include "glthreads.h"
#include <memory.h>

typedef struct student_t
{
    char name[30];
    unsigned int age;
    unsigned int rollno;
    glthreads_node_type glnode;
} student;

void print_student(student *student)
{
    printf("Student name = %s\n", student->name);
    printf("Age = %u\n", student->age);
    printf("Rollno = %u\n", student->rollno);
}

int main(int argc, char **argv)
{
    printf("hello-world\n");

    student *std_1 = calloc(1, sizeof(student));
    strncpy(std_1->name, "Tien", strlen("Tien"));
    std_1->age = 27;
    std_1->rollno = 1000;
    GLTHEAD_INIT_NODE((&std_1->glnode));

    student *std_2 = calloc(1, sizeof(student));
    strncpy(std_2->name, "Tran", strlen("Tran"));
    std_2->age = 27;
    std_2->rollno = 2000;
    GLTHEAD_INIT_NODE((&std_2->glnode));

    student *std_3 = calloc(1, sizeof(student));
    strncpy(std_3->name, "Neha", strlen("Neha"));
    std_3->age = 27;
    std_3->rollno = 3000;
    GLTHEAD_INIT_NODE((&std_3->glnode));

    glthreads_tree_type *glthread = calloc(1, sizeof(glthreads_tree_type));
    glthread_init_thread(glthread, offsetof(student, glnode));
    glthread_add(glthread, &std_1->glnode);
    glthread_add(glthread, &std_2->glnode);
    glthread_add(glthread, &std_3->glnode);

    student *print_data = NULL;
    ITERATE_THREAD_BEGIN(glthread, student, print_data)
    {
        print_student(print_data);
    } ITERATE_THREAD_END;

    glthread_remove(glthread, &std_2->glnode);
    glthread_remove(glthread, &std_3->glnode);
    glthread_remove(glthread, &std_1->glnode);

    printf("After remove std 1\n");
    
    ITERATE_THREAD_BEGIN(glthread, student, print_data)
    {
        print_student(print_data);
    } ITERATE_THREAD_END;

    return 0;
}