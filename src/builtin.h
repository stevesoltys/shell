/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * builtin.h
 * This file contains function prototypes and a structure for builtins.c.
 */

#ifndef _BUILTIN_H_
#define _BUILTIN_H_

#define BUILTIN_SIZE 2

#include "command.h"

/*
 * Structure for built-in functions. Contains their name and a pointer to the built-in function.
 */
typedef struct builtins {
    char *name;

    int (*f)(int, char **);
} builtins_t;

/*
 * Gets the position of a built-in function in the pre-defined array.
 */
int get_position(char *);

/*
 * Built-in "exit" function. Exits with 0 if there are no parameters, otherwise exits with the first parameter.
 */
int exit_b(int, char **);

/*
 * Built-in "cd" function. Changes the current working directory based on the number of arguments.
 */
int cd_b(int, char **);

/*
 * Pre-defined array of built-in functions.
 */
static const builtins_t functions[] = {
        {"exit", &exit_b},
        {"cd",   &cd_b}
};

#endif
