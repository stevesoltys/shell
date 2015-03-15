#ifndef _SHELL_H_
#define _SHELL_H_

typedef struct shell {
} shell_t;

/*
 * Creates a shell. The caller is responsible for freeing the
 * allocated memory.
 */
shell_t *create_shell();

/*
 * Destroys an indexer.
 */
void destroy_shell(shell_t *);

/*
 * Runs the shell.
 */
bool run_shell(shell_t *);

#endif