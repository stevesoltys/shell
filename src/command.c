#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
#include "command.h"

/*
 * Creates a command. The caller is responsible for freeing the allocated memory.
 */
command_t *create_command(char *name, list_t *args) {
    command_t *command = malloc(sizeof(command_t));

    if (command == NULL) {
        fprintf(stderr, "Error creating command!\n");
        return NULL;
    }

    command->name = strdup(name);
    command->args = args;
    return command;
}

/*
 * Destroys a command.
 */
void destroy_command(command_t *command) {
    destroy_list(command->args);
    free(command->name);
    free(command);
}