#ifndef _SORTED_LIST_H_
#define _SORTED_LIST_H_

#include <stdbool.h>

/*
 * Destroy function for a list object. Implemented by the caller.
 */
typedef void destroy_function_t(void *);

/*
 * An element in a list.
 */
typedef struct list_element {
    struct list_element *next;
    void *value;
} list_element_t;

/*
 * A list.
 */
typedef struct sorted_list {
    destroy_function_t *destroy_function;
    list_element_t *head;
} list_t;

/*
 * Creates a list. The caller is responsible for freeing
 * the allocated memory using destroy_list.
 */
list_t *create_list(destroy_function_t *);

/*
 * Destroys a list.
 */
void destroy_list(list_t *);

/*
 * Creates an element for a sorted_list. The caller is responsible for freeing
 * the allocated memory.
 */
list_element_t *create_list_element(void *, list_element_t *);

/*
 * Destroys a list element.
 */
void destroy_list_element(list_t *, list_element_t *);

/*
 * Insert function for a list_t.
 */
bool insert_object(list_t *, void *);

/*
 * An iterator for a list.
 */
typedef struct list_iterator {
    list_element_t *current_index;
} list_iterator_t;

/*
 * Creates a list iterator, given the list.
 */
list_iterator_t *create_iterator(list_t *);

/*
 * Destroys a list iterator.
 */
void destroy_iterator(list_iterator_t *);

/*
 * Gets the current item in the list iterator,
 * and advances to the next index.
 */
void *get_item(list_iterator_t *);

/*
 * Gets the next item in the list iterator.
 */
void *next_item(list_iterator_t *);

#endif