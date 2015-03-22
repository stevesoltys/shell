//
// Created by Steve Soltys on 3/16/15.
//

#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "process.h"
#include "command.h"
#include "builtins.h"

/*
 * Creates a process, given the pid.
static process_t *create_process(pid_t id) {
    process_t *process = malloc(sizeof(process_t));

    if (process == NULL) {
        fprintf(stderr, "Error creating process object!\n");
        return NULL;
    }

    process->id = id;
    return process;
}

 * Destroys a process.
static void destroy_process(process_t *process) {
    free(process);
}

 * Reads the parameter list of the given command and stores them in the given parameter array.
 */
static void set_parameters(command_t *command, char **parameters) {
    list_iterator_t *parameter_iterator = create_iterator(command->parameters);
    int parameter_index = 0;
    char *parameter = get_item(parameter_iterator);
    while (parameter != NULL) {
        parameters[parameter_index++] = parameter;
        parameter = next_item(parameter_iterator);
    }
    parameters[get_size(command->parameters)] = NULL;
    destroy_iterator(parameter_iterator);
}

/*
 * Runs a command, given the input and output file descriptors. Note that if either array contains file descriptors of
 * the value '-1', piping will be ignored for that direction.
 */
static void run_command(command_t *command, int input_fd[], int output_fd[]) {
    int size = get_size(command->parameters);
    char *parameters[size];
    set_parameters(command, parameters);

    int function_position = get_position(command->file);

    if (function_position >= 0) {
        functions[function_position].f(size - 1, parameters);
    } else {
        /* Flag indicating whether we should pipe input for this command. */
        bool pipe_input = input_fd[0] != -1 && input_fd[1] != -1;
        /* Flag indicating whether we should pipe output for this command. */
        bool pipe_output = output_fd[0] != -1 && output_fd[1] != -1;

        /* Time to fork the new child process. */
        pid_t process_id = fork();
        if (process_id == 0) {
            /* If we should pipe the standard input, we do so. */
            if (pipe_input) {
                dup2(input_fd[0], STDIN_FILENO);
                close(input_fd[1]);
            }

            /* If we should pipe the standard output, we do so. */
            if (pipe_output) {
                dup2(output_fd[1], STDOUT_FILENO);
                close(output_fd[0]);
            }

            /* Next, we create a local array of parameters and use the set_parameters function to populate it. */

            /* Time to execute our command! */
            execvp(command->file, parameters);
            perror("execvp");
            exit(EXIT_FAILURE);
        } else if (process_id == -1) {
            /* There was an error during fork() */
            perror("fork");
            exit(EXIT_FAILURE);
        }

        /* If we piped input for this process, we close the file descriptors on the parent process. */
        if (pipe_input) {
            close(input_fd[0]);
            close(input_fd[1]);
        }
    }
}

/*
 * Runs a list of commands, waits for them to terminate, and returns their exit statuses.
 */
void run_commands(list_t *commands) {
    /* File descriptors used for piping the input of a process. */
    int input_fd[2];
    /* For the first command, we won't ever be piping the standard input. */
    input_fd[0] = input_fd[1] = -1;

    /* Create an interator for our command list. */
    list_iterator_t *iterator = create_iterator(commands);
    command_t *command = get_item(iterator);

    /* Iterate through commands, creating processes and piping them together. */
    while (command != NULL) {
        /* If we have a command next in the queue, we'll need to pipe the output of this process. */
        bool should_pipe_output = has_next(iterator);

        if (should_pipe_output) {
            /* File descriptors for piping the output of this process. */
            int output_fd[2];
            /* Create our file descriptors. */
            if (pipe(output_fd) == -1) {
                perror("pipe");
                exit(EXIT_FAILURE);
            }

            /* Time to run the command and get our process! */
            run_command(command, input_fd, output_fd);

            /* Set the input file descriptor, used for piping output to the next command. */
            input_fd[0] = output_fd[0];
            input_fd[1] = output_fd[1];
        } else {
            /* Dummy file descriptors. */
            int output_fd[2];
            /* We have no need to pipe output, since there are no commands after this one. */
            output_fd[0] = output_fd[1] = -1;

            /* Time to run our command and get our process! */
            run_command(command, input_fd, output_fd);
        }

        /* Onto the next command! */
        command = next_item(iterator);
    }
    destroy_iterator(iterator);

    /* Wait for our child processes to die. */
    int process_id, child_status;
    while ((process_id = wait(&child_status)) != -1) {
        printf("Process %d exits with %d\n", process_id, child_status);
    }
}
