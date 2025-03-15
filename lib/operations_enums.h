#ifndef ENUMS_H
#define ENUMS_H

#include <stdio.h>

typedef enum {
    META_COMMAND_SUCCESS,
    META_COMMAND_FAILURE,
    META_COMMAND_UNRECOGNISED,
} MetaCommandState;

typedef enum {
    PREPARE_SUCCESS,
    PREPARE_SYNTAX_ERROR,
    PREPARE_UNRECOGNISED_STATEMENT,
} PrepareState;

typedef enum {
    TableNotFound,
    TableFound,
    DatabaseNotFound,
    DatabaseFound,
    RowNotFound,
    RowFound,
} SearchState;

typedef enum {
    STATEMENT_INSERT,
    STATEMENT_SELECT,
    STATEMENT_DELETE,
    STATEMENT_UPDATE,
} StatementType;


#endif