#include <stdio.h>
#include <stdlib.h>
#include "database.h"

#ifndef UNDO_REDO_H
#define UNDO_REDO_H

typedef struct DatabaseState{
    DatabaseState* next;
    DatabaseState* prev;
    DatabaseState* tail;
    Database* db;
} DatabaseState;

typedef struct {
    DatabaseState* head;
} DatabaseStack;

void add_state(Database* db) {

}

Database* pop_state(DatabaseStack* stack) {

}

DatabaseStack* init_database_stack() {

}

void close_database_stack() {

}


//TABLE UNDO REDO CODE STARTS FROM HERE


#endif
