#include "single_linked_list.h"

SLLNode *newNode(SLLNode *next, int el) {
  SLLNode *node = (SLLNode *)malloc(sizeof(SLLNode));
  if (node == NULL)
    return NULL;
  node->next = next;
  node->content = el;
  return node;
}

bool sll_push(SLLNode **start, int index, int new_el) {
  if (start == NULL || index < 0)
    return false;
  if (index == 0) {
    SLLNode *head = newNode(*start, new_el);
    if (head == NULL)
      return false;
    *start = head;
    return true;
  }
  SLLNode *cur = *start;
  if (cur == NULL)
    return false;
  for (int cnt = 0; cnt < index - 1; cnt++) {
    if (cur->next == NULL)
      return false;
    cur = cur->next;
  }
  SLLNode *new = newNode(cur->next, new_el);
  if (new == NULL)
    return false;
  cur->next = new;
  return true;
}

bool sll_pop(SLLNode **start, int index) {
  if (start == NULL || *start == NULL || index < 0)
    return false;
  if (index == 0) {
    SLLNode *next = (*start)->next;
    free(*start);
    *start = next;
    return true;
  }
  SLLNode *cur = *start;
  for (int cnt = 0; cnt < index - 1; cnt++) {
    if (cur->next == NULL)
      return false;
    cur = cur->next;
  }
  if (cur->next == NULL)
    return false;
  SLLNode *temp = cur->next->next;
  free(cur->next);
  cur->next = temp;
  return true;
}

int *sll_get(SLLNode *start, int index) {
  if (start == NULL || index < 0)
    return NULL;
  SLLNode *cur = start;
  for (int cnt = 0; cnt < index; cnt++) {
    if (cur->next == NULL)
      return NULL;
    cur = cur->next;
  }
  return &cur->content;
}

int sll_count(const SLLNode *start) {
  const SLLNode *cur = start;
  int cnt = 0;
  while (cur != NULL) {
    cur = cur->next;
    cnt += 1;
  }
  return cnt;
}

void sll_free(SLLNode *start) {
  if (start == NULL)
    return;
  SLLNode *cur = start;
  SLLNode *next = start->next;
  while (next != NULL) {
    free(cur);
    cur = next;
    next = next->next;
  }
  free(cur);
}