/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Shell
 * shell.h
 * This file contains function prototypes for shell.c.
 */

#ifndef _SHELL_H_
#define _SHELL_H_

#define MAX_COMMAND_LENGTH 1000 * sizeof(char)

typedef struct shell {
} shell_t;

/*
 * Creates a shell. The caller is responsible for freeing the
 * allocated memory.
 */
shell_t *create_shell();

/*
 * Destroys an indexer.
 */
void destroy_shell(shell_t *);

/*
 * Runs the given shell.
 */
void run_shell(shell_t *);

#endif