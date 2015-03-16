#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include "list.h"

/*
 * Interprets the given command.
 */
list_t *interpret_command(char *);

#endif