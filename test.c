#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

int main(int argc, char **argv)
{
    list_t *list = init_list();
    char item_popped[20];

    for (size_t i = 0; i < argc; i++) {
        list_push(list, argv[i]);
    }
    list_print(list);
    printf("size of list: %zu\n\n", list->size);
    if (list_find(list, "hello.world")) {
        printf("found hello.world!\n");
    } else {
        printf("hello.world not found in list!\n");
    }
    // cleanup list
    list_destroy(list);

    return 0;
}
