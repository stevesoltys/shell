//
// Created by nick on 3/16/15.
//

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "builtins.h"

int get_position(char* name)
{
    int position = -1;
    int i = 0;
    for(i = 0; i < BUILTIN_SIZE; i++)
    {
        if(strcmp(name,functions[i].name) == 0)
        {
            position = i;
            break;
        }
    }

    return position;
}

int exit_b(int argc, char** argv)
{
    if(argc == 0)
    {
        exit(0);
    }
    else if(argc > 0)
    {
        exit(atoi(argv[1]));
    }

    return 0; // Never reached.
}

int cd_b(int argc, char** argv)
{
    int val = 0;
    if(argc == 0)
    {
        // Change to home directory
        val = chdir(getenv("HOME"));
    }
    else if(argc == 1)
    {
        // Change to given directory.
        val = chdir(argv[1]);
    }
    else if(argc > 1)
    {
        // Too many arguments, print error.
        fprintf(stderr, "cd: too many arguments\n");
        return -1;
    }

    if(val != 0)
    {
        // Problem changing directories, print error.
        fprintf(stderr, "cd: error changing directories, errno: %d\n", errno);
    }

    return val;

}