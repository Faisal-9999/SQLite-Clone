#ifndef OP_ENUMS_H
#define OP_ENUMS_H


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
    STATEMENT_INSERT,
    STATEMENT_SELECT,
} StatementType;


#endif