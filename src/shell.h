/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * shell.h
 * This file contains a function prototype for shell.c.
 */

#ifndef _SHELL_H_
#define _SHELL_H_

#define MAX_COMMAND_LENGTH 1000 * sizeof(char)

/*
 * Runs the given shell.
 */
void run_shell();

#endif