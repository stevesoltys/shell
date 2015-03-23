/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * builtins.c
 * This file contains functions used to execute built-in commands.
 */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "builtins.h"

/*
 * Gets the position of a built-in function in the pre-defined array.
 */
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

/*
 * Built-in "exit" function. Exits with 0 if there are no parameters, otherwise exits with the first parameter.
 */
int exit_b(int argc, char** argv)
{
    if(argc == 0)
    {
        exit(0);
    }
    else if(argc == 1)
    {
        exit(atoi(argv[1]));
    }
    else if(argc > 1)
    {
        fprintf(stderr, "exit: too many arguments\n");
        return -1;
    }

    return 0; // Never reached.
}

/*
 * Built-in "cd" function. Changes the current working directory based on the number of arguments.
 */
int cd_b(int argc, char** argv)
{
    int val = 0;
    if(argc == 0)
    {
        // Change to the home directory
        val = chdir(getenv("HOME"));
    }
    else if(argc == 1)
    {
        // Change to the given directory.
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
