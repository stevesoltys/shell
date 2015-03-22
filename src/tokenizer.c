#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "list.h"

/*
 * Destroy function for lists that tokenize() generates.
 */
static void tokenize_destroy_function(void *object) {
    free(object);
}

/*
 * Allocates a block of memory for a token of the given size, starting at the given pointer.
 */
static char *copy_token(char *start, size_t size) {
    char *token = malloc(size + sizeof(char));
    strncpy(token, start, size);
    sprintf(token + size, "%c", '\0');
    return token;
}

/*
 * Tokenizes the given input and returns the tokens as a list.
 */
list_t *tokenize(char *input) {
    list_t *tokens = create_list(&tokenize_destroy_function);
    char *current_index = input;
    char *last_index = input + strlen(input);
    while (current_index < last_index) {
        char current_char = *current_index;
        if (current_char == '"' || current_char == '\'') {
            current_index += sizeof(char);
            char *next_quote = strchr(current_index, current_char);
            if (next_quote == NULL) {
                fprintf(stderr, "Error while tokenizing input: Could not find the end of an open quote.");
                break;
            }
            size_t token_size = next_quote - current_index;
            insert_object(tokens, copy_token(current_index, token_size));
            current_index = next_quote + sizeof(char);
        } else if (current_char == '|') {
            insert_object(tokens, copy_token(current_index, sizeof(char)));
            current_index += sizeof(char);
        } else if (current_char == ' ' || current_char == '\t') {
            current_index += sizeof(char);
        } else {
            char *start_index = current_index;
            while (current_index <= last_index) {
                char token_char = *current_index;
                if (token_char == '|' || token_char == ' ' || current_index == last_index) {
                    size_t token_size = current_index - start_index;
                    insert_object(tokens, copy_token(start_index, token_size));
                    break;
                }
                current_index += sizeof(char);
            }
        }
    }
    return tokens;
}
