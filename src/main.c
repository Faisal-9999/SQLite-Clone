#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../lib/operations_enums.h"
#include "../lib/misc_structs.h"

void print_prompt();
void execute_statement(Statement* statement);
PrepareState prepare_statement(char* input, Statement* statement);
MetaCommandState do_meta_command(char* user_command);

void main() {

    printf("SQLite Clone version 0.0.1 2025\nEnter '.help' for usage hints.\nConnected to a transient in-memory database.");

    while (true) {
        char input[1024];
        printf("\nSQLite Clone> ");

        fgets(input, 1024, stdin);

        for (int i = 0; i < 1024; i++) {
            if (*(input + i) == '\n') {
                *(input + i) = '\0';
                break;
            }
        }

        if (input[0] == '.') {
            switch (do_meta_command(input)) {
            case (META_COMMAND_SUCCESS):
                printf("Successfully Executed: %s", input);
                continue;

            case (META_COMMAND_FAILURE):
                printf("Error Executing: %s", input);
                continue;

            case (META_COMMAND_UNRECOGNISED):
                printf("Unknown Meta Command: %s", input);
                continue;
            default:
                exit(EXIT_FAILURE);
                break;
            }
            
        }

        Statement statement;
        switch (prepare_statement(input, &statement)) {
            case PREPARE_SUCCESS:
                execute_statement(&statement);
                continue;

            case PREPARE_SYNTAX_ERROR:
                printf("Incorrect syntax used after %.6s", input);
                continue;
            
            case PREPARE_UNRECOGNISED_STATEMENT:
                printf("Command %s doesn't exist", input);
                continue;
            default:
                continue;
        }
    }
}

MetaCommandState do_meta_command(char* user_command) {

    //TODO: ADD MORE META COMMANDS
    if (strcmp(user_command, ".exit") == 0) {
        exit(EXIT_SUCCESS);
    }
    else if (strcmp(user_command, ".tables")) {
        
    }
    else {
        return META_COMMAND_UNRECOGNISED;
    }
}

PrepareState prepare_statement(char* input, Statement* statement) {

    //TODO: MAKE CHANGES HERE IN ACCORDANCE TO NEW 

    if (strncmp(input, "insert", 6) == 0) {
        statement->type = STATEMENT_INSERT;

        //int assigned_args = sscanf();

        // if (assigned_args < 3) {
        //     return PREPARE_SYNTAX_ERROR;
        // }

        return PREPARE_SUCCESS;
    }

    if (strncmp(input, "select", 6) == 0) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNISED_STATEMENT;
}

void execute_statement(Statement* statement) {

    //TODO: ADD NEW CASES
    switch (statement->type) {
    case STATEMENT_INSERT:
        printf("Insertion Executed");
        break;
    case STATEMENT_SELECT:
        printf("Selection Executed");
        break;
    default:
        break;
    }
}