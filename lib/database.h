#include <stdio.h>
#include <stdlib.h>
#include "table.h"

#ifndef DATABSE_H
#define DATABASE_H


typedef struct {
    Table* tables;
} Database;

void list_tables(Database* database) {
    if (database->tables == NULL) {
        
    }
    
}

void delete_table(char* table_name) {

}

void add_table(Table* table) {
    
}

void close_database(Database* database) {
    free(database->tables);
    free(database);
}

Database* init_database() {

}

Database* load_database() {

}

Database* save_database() {

}


#endif