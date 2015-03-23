/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Shell
 * main.c
 * This file creates, runs, and destroys a single shell.
 */

#include <stdlib.h>
#include "shell.h"

int main(int argc, char **argv) {
    shell_t *shell = create_shell();
    run_shell(shell);
    destroy_shell(shell);
    return EXIT_SUCCESS;
}