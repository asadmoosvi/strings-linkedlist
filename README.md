## Simple Linked List for Strings in C

Doesn't have all the functionality yet but gets the job done.

### Basic Usage
``` C
#include <stdio.h>
#include "linkedlist.h"
#include <string.h>

int main(void)
{
    list_t *list = init_list();
    char popped_item[20];

    list_print(list);

    list_push(list, "hello");
    list_push(list, "world");
    list_print(list);

    list_pop(list, popped_item);
    if (strlen(popped_item) != 0)
        printf("popped: %s\n", popped_item);

    list_pop(list, popped_item);
    if (strlen(popped_item) != 0)
        printf("popped: %s\n", popped_item);

    list_print(list);

    list_destroy(list);
    return 0;
}
```
