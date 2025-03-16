#ifndef STACK_H
#define STACK_H

#include "../lib/table.h"
#include <stdlib.h>

//TODO: FIX THE ISSUE WHERE the Table.h file cant see the Stack struct in this but it can see the stacknode
//TODO: MIGHT BE DUE TO THE CIRCULAR DEPENDENCY SINCE THIS FILE IS INCLUDED THERE AND THAT FILE IS INCLUDED HERE

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
    int size;
} Stack;

Stack* init_stack() {
    Stack* stack = (Stack*) malloc (sizeof(Stack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    return stack;
}

void push(Stack* stack, TableNode* row) {
    stack->size++;
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

    stack->size--;

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