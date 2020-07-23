#include <stdio.h>
#include "linkedlist.h"

#define LEN 50000

int main(int argc, char **argv)
{
    list_t *l = init_list();
    for (size_t i = 0; i < LEN; i++) {
        printf("%zu: pushing my_string to list\r", i);
        fflush(stdout);
        list_push(l, "my_string");
    }
    printf("\n");

    list_print(l);
    list_destroy(l);
    return 0;
}

