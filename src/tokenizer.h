/* Steve Soltys & Nick Burkard
 * CS 416
 * Assignment 5 - Simple Shell
 * tokenizer.h
 * This file contains function prototypes for tokenizer.c.
 */

#ifndef _TOKENIZER_H_
#define _TOKENIZER_H_

#include "list.h"

/*
 * Tokenizes the given input and returns the tokens as a list.
 */
list_t *tokenize(char*);

#endif