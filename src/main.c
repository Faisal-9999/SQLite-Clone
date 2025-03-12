#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct {
    char* buffer;
    size_t buffer_length;
    size_t input_length;
} InputBuffer;

int prompts = 1;

InputBuffer* new_input_buffer();
void read_input(InputBuffer* input);
void close_input_buffer(InputBuffer* buffer);
void print_prompt();
size_t getline(char** lineptr, size_t* n, FILE* stream);

void main() {

    InputBuffer* input_buffer = new_input_buffer();

    while (1) {
        if(prompts == 1) print_prompt();
        printf("\nSQLite Clone> ");
        read_input(input_buffer);


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

void print_prompt() {
    printf("SQLite Clone version 0.0.1 2024\nEnter '.help' for usage hints.\nConnected to a transient in-memory database.");
    prompts++;
}

//this is a general purpose implementation suitable for both files and user input
size_t getline(char** lineptr, size_t* n, FILE* stream) {
    if (lineptr == NULL || n == NULL || stream == NULL) {
        return -1;
    }

    int c = fgetc(stream);

    if (c == EOF) {
        return -1;
    }

    if (*lineptr == NULL) {
        *lineptr = (char*) malloc(128);
        *n = 128;
    }


    size_t pos = 0;

    while (c != EOF) {
        if (pos + 1 >= *n) {
            *lineptr = (char*) realloc (*lineptr, *n + (*n / 4));

            if (*lineptr == NULL) {
                return -1;
            }
            
            *n += *n/4;
        }

        if (c == '\n') {
            break;
        }
        

        ((unsigned char*)(*lineptr))[pos++] = c;
        fgetc(stream);
    }

    (*lineptr)[pos] = '\n';
    
    return pos;
}

void read_input(InputBuffer* inputbuffer) {
    size_t bytes_read = getline(&(inputbuffer->buffer), &(inputbuffer->buffer_length), stdin);

    if (bytes_read <= 0) {
        printf("Error reading input");
        exit(1);
    }

    inputbuffer->input_length = bytes_read - 1;
    inputbuffer->buffer[bytes_read - 1] = 0;
}