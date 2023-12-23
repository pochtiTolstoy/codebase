#include <stdio.h>
#include "list.h"

void print_item(Item item);

int main(void) {
  List l1;
  init_list(&l1);
  insert(&l1, "Hello world!");
  traverse(&l1, print_item);
  empty_the_list(&l1);
  return 0;
}

void print_item(Item item) {
  printf("%s\n", item);
}
