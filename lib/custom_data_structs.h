#include "operations_enums.h"
#include <stdint.h>

#ifndef CUSTOM_DS_H
#define CUSTOM_DS_H

#define sizeof_attribute(Struct, attribute) sizeof(((Struct*)0)->attribute)

#define PAGE_SIZE 4096
#define ID_SIZE sizeof_attribute(Row, id)
#define USER_SIZE sizeof_attribute(Row, username)
#define EMAIL_SIZE sizeof_attribute(Row, email)
#define ID_OFFSET 0
#define USERNAME_OFFSET (ID_OFFSET + ID_SIZE)
#define EMAIL_OFFSET (USERNAME_OFFSET + USER_SIZE)
#define ROW_SIZE (ID_SIZE + USER_SIZE + EMAIL_SIZE)
#define ROWS_PER_PAGE (PAGE_SIZE / ROW_SIZE)

#define USERNAME_LENGTH 32
#define EMAIL_LENGTH 255
#define TABLE_MAX_PAGES 100

#define TABLE_MAX_ROWS (ROWS_PER_PAGE * TABLE_MAX_PAGES)

typedef struct {
    uint32_t num_rows;
    void* pages[TABLE_MAX_PAGES];
} Table;

typedef struct {
    uint32_t id;
    char username[USERNAME_LENGTH];
    char email[EMAIL_LENGTH];
} Row;

typedef struct {
    StatementType type;
    Row row;
} Statement;

#endif
