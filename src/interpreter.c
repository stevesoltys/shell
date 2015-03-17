#include <string.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "command.h"

/*
 * Destroy function for lists that parse_command() generates.
 */
static void command_list_destroy_function(void *object) {
    destroy_command((command_t *) object);
}

/*
 * Destroy function for lists that parse_parameters() generates.
 */
static void parameter_list_destroy_function(void *object) {
    free((char *) object);
}

/*
 * Parses the parameters for a command, given the token iterator.
 */
static list_t *parse_parameters(list_iterator_t *iterator) {
    list_t *arguments = create_list(&parameter_list_destroy_function);
    char *token = get_item(iterator);
    while (token != NULL) {
        if (strcmp(token, "|") != 0) {
            insert_object(arguments, strdup(token));
        } else {
            break;
        }
        token = next_item(iterator);
    }
    return arguments;
}

/*
 * Interprets the given input and returns a list of commands.
 */
list_t *interpret_input(char *input) {
    list_t *commands = create_list(&command_list_destroy_function);
    list_t *tokens = tokenize(input);
    list_iterator_t *iterator = create_iterator(tokens);
    char *command_name = get_item(iterator);
    while (command_name != NULL) {
        list_t *command_parameters = parse_parameters(iterator);
        insert_object(commands, create_command(command_name, command_parameters));
        command_name = next_item(iterator);
    }
    destroy_iterator(iterator);
    destroy_list(tokens);
    return commands;
}