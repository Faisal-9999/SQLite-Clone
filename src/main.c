#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define _POSIX_C_SOURCE 200809L


typedef struct {
    char* buffer;
    size_t buffer_length;
    size_t input_length;
} InputBuffer;

const int prompts = 1;

InputBuffer* new_input_buffer();
void read_input(InputBuffer* input);
void close_input_buffer(InputBuffer* buffer);
void print_prompt();
ssize_t getline(char** lineptr, size_t* n, FILE* stream);

void main() {

    InputBuffer* input_buffer = new_input_buffer();

    while (1) {
        print_prompt();


        if (strcmp(input_buffer->buffer, ".exit") == 0) {
            close_input_buffer(input_buffer);
            exit(0);
        }
        else {
            printf("Unrecognised Command '%s'.\n", input_buffer->buffer);
        }
    }
    

}

InputBuffer* new_input_buffer() {
    InputBuffer* inputbuffer = (InputBuffer*) malloc(sizeof(InputBuffer));

    inputbuffer->buffer = NULL;
    inputbuffer->buffer_length = 0;
    inputbuffer->input_length = 0;

    return inputbuffer;
}

void close_input_buffer(InputBuffer* inputbuffer) {
    free(inputbuffer->buffer);
    free(inputbuffer);
}

void read_input(InputBuffer* inputbuffer) {
    ssize_t bytes_read = getline(&(inputbuffer->buffer), &(inputbuffer->buffer_length), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input");
        exit(1);
    }

    inputbuffer->input_length = bytes_read - 1;
    inputbuffer->buffer[bytes_read - 1] = 0;
}

void print_prompt() {
    if (prompts == 1) {
        printf("SQLite Clone version 0.0.1 2024\nEnter '.help' for usage hints.\nConnected to a transient in-memory database.\nSQLite Clone> ");
        return;
    }

    printf("\nSQLite Clone> ");
}