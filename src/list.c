#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

/*
 * Creates a list.
 */
list_t *create_list(destroy_function_t *destroy_func) {
    list_t *list = malloc(sizeof(list_t));

    if (list == NULL) {
        fprintf(stderr, "Error creating list!\n");
        return NULL;
    }

    list->destroy_function = destroy_func;
    list->head = NULL;
    return list;
}

/*
 * Destroys a list.
 */
void destroy_list(list_t *list) {
    list_element_t *index = list->head;
    while (index != NULL) {
        list_element_t *next = index->next;
        destroy_list_element(list, index);
        index = next;
    }
    free(list);
}

/*
 * Creates an element for a list.
 */
list_element_t *create_list_element(void *value, list_element_t *next) {
    /* We dynamically allocate memory for an element node */
    list_element_t *element = malloc(sizeof(list_element_t));

    if (element == NULL) {
        fprintf(stderr, "Error creating list element!\n");
        return NULL;
    }

    /* We set the value and the next node for the new element.*/
    element->value = value;
    element->next = next;
    return element;
}

/*
 * Destroys a list element.
 */
void destroy_list_element(list_t *list, list_element_t *element) {
    list->destroy_function(element->value);
    free(element);
}

/*
 * Inserts a given element directly after the given index.
 */
static void insert_after(list_element_t *index, list_element_t *element) {
    list_element_t *tmp = index->next;
    element->next = tmp;
    index->next = element;
}

/*
 * Inserts an object in the given list. This function returns true when it succeeds, and false when it fails.
 */
bool insert_object(list_t *list, void *object) {
    if (list->head == NULL) {
        /* If the head is null, we insert the object as the head. */
        list->head = create_list_element(object, NULL);
    } else {
        list_element_t *index = list->head;
        /* We loop through the list and insert the object when we get to the end. */
        while (true) {
            if (index->next == NULL) {
                /* We insert the object at the end. */
                insert_after(index, create_list_element(object, NULL));
                return true;
            }
            index = index->next;
        }
    }
    return false;
}

/*
 * Gets the current size of the list.
 */
int get_size(list_t *list) {
    list_iterator_t *iterator = create_iterator(list);
    void *object = get_item(iterator);
    int size = 0;
    while (object != NULL) {
        size++;
        object = next_item(iterator);
    }
    destroy_iterator(iterator);
    return size;
}

/*
 * Constructs a list iterator, given the list.
 */
list_iterator_t *create_iterator(list_t *list) {
    list_iterator_t *iterator = malloc(sizeof(list_iterator_t));

    /* list must be initialized */
    if (list == NULL) {
        fprintf(stderr, "Error creating iterator!\n");
        return NULL;
    }
    iterator->current_index = list->head;
    return iterator;
}

/*
 * Destroys a list iterator.
 */
void destroy_iterator(list_iterator_t *iterator) {
    free(iterator);
}

/*
 * Gets the value of the current node that the list iterator is pointing to.
 */
void *get_item(list_iterator_t *iterator) {
    if (iterator->current_index != NULL) {
        return iterator->current_index->value;
    }
    return NULL;
}

/*
 * Gets the next item in the list iterator, and sets the current index to that node.
 */
void *next_item(list_iterator_t *iterator) {
    if (iterator->current_index != NULL) {
        list_element_t *next_element = iterator->current_index->next;
        if (next_element != NULL) {
            iterator->current_index = next_element;
            return next_element->value;
        }
    }
    return NULL;
}

/*
 * Checks whether there are any items remaining in the list.
 */
bool has_next(list_iterator_t *iterator) {
    if (iterator->current_index != NULL) {
        list_element_t *next_element = iterator->current_index->next;
        if (next_element != NULL) {
            return true;
        }
    }
    return false;
}
