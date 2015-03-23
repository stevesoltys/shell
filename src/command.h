/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * command.h
 * This file contains function prototypes and a structure for command.h.
 */

#ifndef _COMMAND_H_
#define _COMMAND_H_

#include <sched.h>
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
 * Runs a list of commands, waits for them to terminate, and returns their exit statuses.
 */
void run_command_list(list_t *commands);

#endif