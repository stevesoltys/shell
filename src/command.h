#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "list.h"

typedef struct command {
    char *name;
    list_t *args;
} command_t;

/*
 * Creates a command. The caller is responsible for freeing the allocated memory.
 */
command_t *create_command(char *, list_t *);

/*
 * Destroys a command.
 */
void destroy_command(command_t *);

#endif