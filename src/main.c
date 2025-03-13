#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prompts = 1;

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_FAILURE,
    META_COMMAND_UNRECOGNISED,
} MetaCommandState;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_UNRECOGNISED_STATEMENT,
} PrepareState;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} StatementType;

typedef struct {
    StatementType type;
} Statement;

void print_prompt();
PrepareState prepare_statement(char* input, Statement* statement);
MetaCommandState do_meta_command(char* user_command);

void main() {

    while (1) {
        if(prompts == 1) print_prompt();
        char input[1024];
        printf("\nSQLite Clone> ");

        fgets(input, 1024, stdin);

        int pos = 0;

        while (input[pos++] != '\n');
        
        input[pos] = '\0';

        if (input[0] == '.') {
            switch (do_meta_command(input)) {
            case (META_COMMAND_SUCCESS):
                printf("Successfully Executed: %s", input);
                continue;

            case (META_COMMAND_FAILURE):
                printf("Error Executing: %s", input);
                continue;

            case (META_COMMAND_UNRECOGNISED):
                printf("Unknown Command: %s", input);
                continue;
            default:
                exit(EXIT_FAILURE);
                break;
            }
            
        }
        else {
            printf("Unrecognised Command '%s'.", input);
        }


        Statement statement;
        switch (prepare_statement(input, &statement)) {
        case PREPARE_SUCCESS:
            /* code */
            continue;
        
        case PREPARE_UNRECOGNISED_STATEMENT:

            continue;
        default:
            break;
        }
    }
}

void print_prompt() {
    printf("SQLite Clone version 0.0.1 2025\nEnter '.help' for usage hints.\nConnected to a transient in-memory database.");
    prompts++;
}

MetaCommandState do_meta_command(char* user_command) {
    if (strcmp(user_command, ".exit") == 0) {
        exit(EXIT_SUCCESS);
    }
    else {
        return META_COMMAND_UNRECOGNISED;
    }
}

PrepareState prepare_statement(char* input, Statement* statement) {
    if (strcmp(input, "insert") == 0) {
        statement->type = STATEMENT_INSERT;
        return PREPARE_SUCCESS;
    }

    if (strncmp(input, "select", 6)) {
        statement->type = STATEMENT_SELECT;
        return PREPARE_SUCCESS;
    }

    return PREPARE_UNRECOGNISED_STATEMENT;
}

void execute_statement(Statement* statement) {
    if (statement->type == STATEMENT_INSERT) {
        /* code */
    }
    
}
