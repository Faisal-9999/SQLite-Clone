#ifndef TABLE_H
#define TABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <../data_structures/RowStack.h>
#include "operations_enums.h"

//TODO: FOCUS ON TABLE WORKING FOR NOW

typedef struct TableNode {
    TableNode* left;
    TableNode* right;
    int* ID;
    char username[100];
    char email[100];
} TableNode;

TableNode* init_table_node(int* id, char* username, char* email) {
    TableNode* row = (TableNode*) malloc (sizeof(TableNode));
    row->ID = id;
    strcpy(row->username, username);
    strcpy(row->email, email);
    return row;
}

typedef struct {
    char table_name[100];
    int current_ID;
    TableNode* root;
    size_t table_rows;
} Table;


Table* init_Table() {
    Table* table = (Table*) malloc (sizeof(Table));
    table->root = NULL;
    table->table_rows = 0;
    table->current_ID = 0;
    return table;
}

SearchState search_with_ID(Table* table, TableNode* row, size_t ID) {
    if (table->root == NULL) {
        return RowNotFound;
    }

    TableNode* current = table->root;

    


    
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