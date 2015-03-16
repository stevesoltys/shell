#include <stdio.h>
#include <string.h>
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
    while (token != NULL)
    {
        char* name;
        list_t* arguments = create_list(&command_list_destroy_function);
        int command = 1,
            first = 1;

        while(command)
        {
            if(first)
            {
                name = token;
                printf("Name: %s\n", name);
                first = 0;
            }
            else if(strcmp("|", token) != 0)
            {
                printf("Parameter: %s\n", token);
                insert_object(arguments, token);
            }
            else if(strcmp("|", token) == 0)
            {
                printf("Pipe\n");
                command_t* temp = create_command(name, arguments);
                insert_object(commands, temp);
                command = 0;
            }
            token = next_item(iterator);
        }
    }
    destroy_iterator(iterator);
    destroy_list(tokens);
    return commands;
}