#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include "operations_enums.h"

//TODO: FOCUS ON TABLE WORKING FOR NOW

typedef struct {
    int ID;
    char username[100];
    char email[100];
} TableNode;

typedef struct {
    char table_name[100];
    TableNode* left_node;
    TableNode* right_node;
    int current_ID;
    size_t table_rows;
} Table;


Table* init_Table() {
    Table* table = (Table*) malloc (sizeof(Table));
    table->left_node = NULL;
    table->right_node = NULL;
    table->table_rows = 0;
    table->current_ID = 0;
    return table;
}

SearchState search_with_ID(Table* table, TableNode* row, size_t ID) {

}

SearchState search_with_username(Table* table, TableNode* row, char* username) {

}

SearchState search_with_email(Table* table, TableNode* row, char* email) {

}

void add_row(Table* table, TableNode* new_row) {

}

void update_row_with_ID(Table* table, size_t ID) {

}

void update_row_with_username(Table* table, char* username) {

}

void update_row_with_email(Table* table, char* email) {

}

void delete_row_with_ID(Table* table, size_t ID) {

}

void delete_row_with_username(Table* table, char* username) {

}

void update_row_with_email(Table* table, char* email) {

}



#endif