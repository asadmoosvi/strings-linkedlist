#include <stdio.h>

#include "linkedlist.h"

#define LEN 50000

int main(int argc, char **argv) {
  list_t *l = init_list();
  for (size_t i = 0; i < LEN; i++) {
    printf("%zu: pushing my_string to list\r", i);
    fflush(stdout);
    list_push(l, "my_string");
  }
  printf("\n");

  list_print(l);
  size_t sz = l->size;
  char popped_item[50];
  for (size_t i = 0; i < sz; i++) {
    list_pop(l, popped_item);
    printf("Popped '%s'\n", popped_item);
    printf("New size: %zu\n", l->size);
  }

  list_destroy(l);
  return 0;
}
