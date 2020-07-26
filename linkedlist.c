#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

node_t *init_node(const char *data)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = malloc(strlen(data) + 1);
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

void destroy_node(node_t *node)
{
    if (node == NULL)
        return;

    free(node->data);
    free(node);
}

list_t *init_list(void)
{
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

void list_destroy(list_t *list)
{
    node_t *node_ptr = list->head;
    node_t *next_ptr;

    while (node_ptr != NULL) {
        next_ptr = node_ptr->next;
//        printf("freeing node: %p\n", node_ptr);
//        printf("node data: %s\n", node_ptr->data);
//        printf("node next: %p\n", node_ptr->next);
        destroy_node(node_ptr);
        node_ptr = next_ptr;
    }

    free(list);
}

void list_push(list_t *list, const char *data)
{
    node_t *node = init_node(data);
    node->next = list->head;
    list->head = node;
    (list->size)++;
}

void list_pop(list_t *list, char *buf)
{
    if (list->head == NULL) {
        fprintf(stderr, "warning: no items left in list\n");
        *buf = '\0';
        return;
    }

    node_t *node_ptr = list->head;
    node_t *last_node = node_ptr;

    while (node_ptr->next != NULL) {
        node_ptr = node_ptr->next;
        if (node_ptr->next != NULL)
            last_node = node_ptr;
    }
    strcpy(buf, node_ptr->data);

  // if last_node == node_ptr then theres only 1 item in the list
  // that we deleted so we have to reset head to NULL

    if (last_node == node_ptr) {
        destroy_node(node_ptr);
        list->head = NULL;
    } else {
        destroy_node(node_ptr);
        last_node->next = NULL;
    }

    (list->size)--;
}

void list_print(list_t *list)
{
    node_t *node_ptr = list->head;
    if (node_ptr == NULL) {
        printf("{ empty list }\n");
        return;
    }

    printf("{ ");
    while (node_ptr != NULL) {
        printf("\"%s\", ", node_ptr->data);
        node_ptr = node_ptr->next;
    }
    printf("}\n");
}

int list_find(list_t *list, const char *data)
{
    node_t *node_ptr = list->head;
    while (node_ptr != NULL) {
        if (strcmp(node_ptr->data, data) == 0)
            return 1;

        node_ptr = node_ptr->next;
    }

    return 0;
}

void node_print(node_t *node)
{
    printf("{ .data = \"%s\", .next = %p }\n", 
            node->data, node->next);
}
