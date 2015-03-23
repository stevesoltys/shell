/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * process.h
 * This file contains function prototypes for process.h.
 */

#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <sched.h>
#include "list.h"


/*
 * Runs a list of commands, waits for them to terminate, and returns their exit statuses.
 */
void run_command_list(list_t *commands);

#endif //_PROCESS_H_
