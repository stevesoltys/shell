#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "shell.h"
#include "interpreter.h"
#include "command.h"
#include "process.h"

/*
* Creates a shell. The caller is responsible for freeing the allocated memory.
*/
shell_t *create_shell() {
    shell_t *shell = malloc(sizeof(shell_t));

    if (shell == NULL) {
        fprintf(stderr, "Error creating shell!\n");
        return NULL;
    }

    return shell;
}

/*
* Destroys the given shell.
*/
void destroy_shell(shell_t *shell) {
    free(shell);
}

/*
 * Gets a line from the standard input and returns it.
 */
static char *get_input() {
    printf("[nobody@nowhere]$ ");
    fflush(stdout);

    char *input = malloc(MAX_COMMAND_LENGTH);
    fgets(input, MAX_COMMAND_LENGTH, stdin);

    /* replace the last character, if it is a new line. */
    size_t last_char = strlen(input) - 1;
    if (input[last_char] == '\n') {
        input[last_char] = '\0';
    }
    return input;
}

/**
* Runs the given shell.
*/
void run_shell(shell_t *shell) {
    while (true) {
        char *input = get_input();
        list_t *commands = interpret_input(input);
        run_commands(commands);
        destroy_list(commands);
        free(input);
    }
}