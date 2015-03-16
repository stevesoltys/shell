#include <stdio.h>
#include "tokenizer.h"
#include "command.h"

/*
 * Destroy function for lists that interpret_command() generates.
 */
static void command_list_destroy_function(void *object) {
    destroy_command((command_t *) object);
}

/*
 * Interprets the given input and returns a list of commands.
 */
list_t *interpret_command(char *input) {
    list_t *commands = create_list(&command_list_destroy_function);
    list_t *tokens = tokenize(input);
    list_iterator_t *iterator = create_iterator(tokens);
    char *token = get_item(iterator);
    while (token != NULL) {
        printf("Token: %s\n", token);
        token = next_item(iterator);
    }
    destroy_iterator(iterator);
    destroy_list(tokens);
    return commands;
}