#include "operations_enums.h"
#include <stdint.h>

#ifndef CUSTOM_DS_H
#define CUSTOM_DS_H

//EACH TABLE WILL BE A BINARY TREE CONSISTING OF NODES WHICH WILL BE THE ROWS
//THE DATABASE WILL BE BINARY TREES EACH NODE BEING A TABLE

//TABLENODE CODE FROM HERE


typedef struct {
    StatementType type;
} Statement;


typedef struct {
    int ID;
    char username[100];
    char email[100];
} TableNode;


//TABLE CODE FROM HERE

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

Table* load_Table(FILE* file) {
    
}

//ADD VARIANTS FOR EACH FUNCTION DEPENDING THE ARGUEMNTS GIVEN BY THE USER FOR EXAMPLE IF THE USER ENTERS
//THAT HE WANTS TO DELETE THE ROW IN WHICH THIS IS THE ID or that DELETE THE ROW IN Which this username is contained
//FOR THIS WILL NEED TWO DIFFERENT FUNCTIONS

void add_row(Table* table, TableNode* new_row) {

}

void update_row(Table* table, size_t ID) {

}

void delete_row() {

}

void delete_in_row() {

//EACH TABLE WILL BE A BINARY TREE CONSISTING OF NODES WHICH WILL BE THE ROWS
//THE DATABASE WILL BE BINARY
}

//DATABASE CODE FROM HERE

typedef struct {
    Table* tables;
} Database;

void delete_table() {

}

void add_table() {

}

Database* init_database() {

}

Database* load_database() {

}



#endif
