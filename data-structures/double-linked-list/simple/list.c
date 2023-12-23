#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "list.h"

void init_list(List* plist) {
  plist->head = NULL;
  plist->items = 0;
}

bool is_empty(const List* plist) {
  return plist->head == NULL;
}

bool is_full(const List* plist) {
  return plist->items == TSIZE;
}

unsigned int item_count(const List* plist) {
  return plist->items;
}

Node* insert(List* plist, const Item item) {
  if (is_full(plist)) {
    printf("Error, list is full! Item: %s\n", item);
    return NULL;
  }
  // alloc Node
  ++plist->items;
  Node* p_node = (Node*) malloc(sizeof(Node));
  // alloc string
  int len = strlen(item);
  p_node->item = (char*) malloc((len + 1) * sizeof(char));
  strcpy(p_node->item, item);
  p_node->item[len] = '\0';
  // rearrange pointers
  p_node->prev = NULL;
  p_node->next = plist->head;
  plist->head = p_node;
  return p_node;
}

void empty_the_list(List* plist) {
  Node* ptr;
  while (plist->head != NULL) {
    ptr = plist->head; 
    plist->head = plist->head->next;
    free(ptr->item);
    free(ptr);
  }
  plist->items = 0;
}

void traverse(const List* plist, void (*pf)(Item item)) {
  Node* ptr = plist->head;
  while (ptr != NULL) {
    (*pf)(ptr->item);
    ptr = ptr->next;
  }
}

















