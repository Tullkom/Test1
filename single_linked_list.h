#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct SLLNode {
  struct SLLNode *next;
  int content;
} SLLNode;

bool sll_push(SLLNode **start, int index, int new_el);

bool sll_pop(SLLNode **start, int index);

int *sll_get(SLLNode *start, int index);

int sll_count(const SLLNode *start);

void sll_free(SLLNode *start);

#endif