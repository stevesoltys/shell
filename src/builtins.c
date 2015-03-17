//
// Created by nick on 3/16/15.
//

#include "builtins.h"

static const builtins_t functions[] =
{
    {"exit", &exit},
    {"cd", &cd}
};

int exit(list_t* args)
{
    return 0;
}

int cd(list_t* args)
{
    return 0;
}