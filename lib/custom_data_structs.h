#include "operations_enums.h"
#include "stdint.h"

#ifndef CUSTOM_DS_H
#define CUSTOM_DS_H

#define USERNAME_SIZE 32
#define EMAIL_SIZE 255

typedef struct {
    uint32_t id;
    char username[USERNAME_SIZE];
    char email[EMAIL_SIZE];
} Row;

typedef struct {
    StatementType type;
    Row row;
} Statement;


#endif
