//
// Created by nick on 3/16/15.
//

#ifndef _SHELL_COMMANDS_H_
#define _SHELL_COMMANDS_H_

#include "command.h"

typedef struct builtins
{
    char* name;
    int (*f)(list_t*);
}builtins_t;

int exit(list_t*);
int cd(list_t*);

#endif //_SHELL_COMMANDS_H_
