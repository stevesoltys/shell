#include <stdlib.h>
#include "shell.h"

/*
* Creates a shell. The caller is responsible for freeing the allocated memory.
*/
shell_t *create_shell() {
    shell_t *shell = malloc(sizeof(shell_t));
    return shell;
}

/*
* Destroys the given shell.
*/
void destroy_shell(shell_t *shell) {
    free(shell);
}