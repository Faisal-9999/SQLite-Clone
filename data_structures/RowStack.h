#ifndef STACK_H
#define STACK_H

#include "../lib/table.h"
#include <stdlib.h>

//TODO: COMPLETE WORK ON STACK FOR PREORDER TRAVERSAL THIS WILL BE USED FOR SEARCHING
//TODO: CONTINUE WORKING ON THE STACK UNTIL ITS FEATURE COMPLETE

typedef struct StackNode {
    StackNode* next;
    StackNode* prev;
    TableNode* row;
} StackNode;

StackNode* init_stacknode(TableNode* row) {
    StackNode* node = (StackNode*) malloc (sizeof(StackNode));
    node->next = NULL;
    node->prev = NULL;
    node->row = row;
    return node;
}

typedef struct {
    StackNode* head;
    StackNode* tail;
} Stack;

void push(Stack* stack, TableNode* row) {
    if (stack->head == NULL) {
        stack->head = init_stacknode(row);
        stack->tail = stack->head;
        return;
    }

    stack->tail->next = init_stacknode(row);
    stack->tail->next->prev = stack->tail;
    stack->tail = stack->tail->next;
}

TableNode* pop(Stack* stack) {
    if (stack->head == NULL) {
        return NULL;
    }

    TableNode* temp = stack->tail->row;
    StackNode* toFree = stack->tail;

    stack->tail = stack->tail->prev;

    if (stack->tail == NULL) {
        stack->head = NULL;
    }
    else {
        stack->tail->next = NULL;
    }

    free(toFree);
    
    return temp;
}



#endif