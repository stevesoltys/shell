#include <stdlib.h>
#include "shell.h"

int main(int argc, char **argv) {
    shell_t *shell = create_shell();
    destroy_shell(shell);
    return EXIT_SUCCESS;
}