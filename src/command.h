#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "list.h"

typedef struct command {
    char *file;
    list_t *parameters;
} command_t;

/*
 * Creates a command. The caller is responsible for freeing the allocated memory.
 */
command_t *create_command(char *, list_t *);

/*
 * Destroys a command.
 */
void destroy_command(command_t *);

/*
 * Prints a string representation of the given command. Used for debugging.
 */
void *print_command(command_t *);

#endif