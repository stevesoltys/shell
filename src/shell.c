/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * shell.c
 * This file contains functions used to create, destroy and manipulate a shell.
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "builtin.h"
#include "shell.h"
#include "interpreter.h"
#include "run.h"


/*
 * Obtains the file name of the current working directory and returns it.
 * TODO: The path should be allocated dynamically so we don't ever go over the character limit.
 */
static char *get_working_directory() {
    char working_directory_path[2048];
    if (getcwd(working_directory_path, sizeof(working_directory_path)) != NULL) {
        char *file_name = working_directory_path;
        while (strchr(file_name, '/') != NULL) {
            file_name = strchr(file_name, '/') + sizeof(char);
        }
        return strdup(file_name);
    }
    perror("getcwd");
    return NULL;
}

/*
 * Writes a shell prompt to the standard output containing the username, hostname, and working directory.
 */
static void display_prompt() {
    char *working_directory = get_working_directory();
    char host_name[16];
    gethostname(host_name, sizeof(host_name));
    printf("[%s@%s %s]$ ", getenv("USER"), host_name, working_directory);
    free(working_directory);
}

/*
 * Gets a line from the standard input and returns it.
 */
static char *get_input() {
    char *input = malloc(MAX_COMMAND_LENGTH);
    if (fgets(input, MAX_COMMAND_LENGTH, stdin) != 0)
    {
        /* replace the last character, if it is a new line. */
        size_t last_char = strlen(input) - 1;
        if (input[last_char] == '\n') {
            input[last_char] = '\0';
        }
    }
    else
    {
        input = NULL;
    }

    return input;
}

/*
 * Gets a single line from the standard input, interprets it, and runs the resulting command(s).
 */
static void run_command_line() {
    char *input = get_input();
    if(input != NULL)
    {
        list_t *commands = interpret_input(input);
        if(commands != NULL)
        {
            run_command_list(commands);
            destroy_list(commands);
        }
        else
        {
            fflush(stderr);
        }
    }
    free(input);
}

/*
 * Runs the shell.
 */
void run_shell()
{
    /* Loop until we reach the end of file. */
    while(!feof(stdin))
    {
        if(isatty(STDIN_FILENO)) display_prompt();
        run_command_line();
    }

    /* Print a newline so the terminal does not start on the wrong line. */
    printf("\n");
}
