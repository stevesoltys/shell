/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * run.h
 * This file contains function prototypes for run.h.
 */

#ifndef _RUN_H_
#define _RUN_H_

#include <sched.h>
#include "list.h"


/*
 * Runs a list of commands, waits for them to terminate, and returns their exit statuses.
 */
void run_command_list(list_t *commands);

#endif
