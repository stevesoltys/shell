/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * interpreter.c
 * This file contains a prototype function for interpreter.c.
 */

#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include "list.h"

/*
 * Interprets the given command.
 */
list_t *interpret_input(char *);

#endif