#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int prompts = 1;

void print_prompt();

void main() {

    while (1) {
        if(prompts == 1) print_prompt();
        char input[1024];
        printf("\nSQLite Clone> ");

        fgets(input, 1024, stdin);

        if (strcmp(input, ".exit") == 0) {
            exit(0);
        }
        else {
            printf("Unrecognised Command '%s'.", input);
        }
    }
}

void print_prompt() {
    printf("SQLite Clone version 0.0.1 2024\nEnter '.help' for usage hints.\nConnected to a transient in-memory database.");
    prompts++;
}