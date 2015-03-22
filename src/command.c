#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"
#include "command.h"

/*
 * Creates a command. The caller is responsible for freeing the allocated memory.
 */
command_t *create_command(char *path, list_t *parameters) {
    command_t *command = malloc(sizeof(command_t));

    if (command == NULL) {
        fprintf(stderr, "Error creating command!\n");
        return NULL;
    }

    command->file = strdup(path);
    command->parameters = parameters;
    return command;
}

/*
 * Destroys a command.
 */
void destroy_command(command_t *command) {
    destroy_list(command->parameters);
    free(command->file);
    free(command);
}

/*
 * Prints a string representation of the given command. Used for debugging.
 */
void *print_command(command_t *command) {
    printf("Command: [file: %s", command->file);
    list_iterator_t *iterator = create_iterator(command->parameters);
    char *parameter = get_item(iterator);
    int count = 0;
    while (parameter != NULL) {
        printf(", parameter %d: %s", count++, parameter);
        parameter = next_item(iterator);
    }
    printf("]\n");
    destroy_iterator(iterator);
}