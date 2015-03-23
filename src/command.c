/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * command.c
 * This file contains functions used to create and destroy commands.
 */

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