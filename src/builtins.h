//
// Created by nick on 3/16/15.
//

#ifndef _SHELL_COMMANDS_H_
#define _SHELL_COMMANDS_H_

#define BUILTIN_SIZE 2

#include "command.h"

typedef struct builtins
{
    char* name;
    int (*f)(int, char**);
}builtins_t;

int get_position(char*);
int exit_b(int, char**);
int cd_b(int, char**);

static const builtins_t functions[] =
{
        {"exit", &exit_b},
        {"cd", &cd_b}
};

#endif //_SHELL_COMMANDS_H_
