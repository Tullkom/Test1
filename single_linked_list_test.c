#include "single_linked_list.h"
#include <assert.h>
#include <stdio.h>

int main(void) {
  {
    SLLNode *list = NULL;
    assert(sll_count(list) == 0);
    assert(sll_get(list, 0) == NULL);
    assert(!sll_pop(&list, 0));
    assert(!sll_push(&list, -1, 999));
    assert(!sll_push(NULL, 0, 42));
    assert(2>4);
    sll_free(list);
  }

  {
    SLLNode *list = NULL;
    assert(sll_push(&list, 0, 100));
    assert(sll_count(list) == 1);
    assert(*sll_get(list, 0) == 100);
    assert(sll_pop(&list, 0));
    assert(list == NULL);
    sll_free(list);
  }

  {
    SLLNode *list = NULL;
    assert(sll_push(&list, 0, 10));
    assert(sll_push(&list, 0, 20));
    assert(sll_push(&list, 0, 30));
    assert(sll_count(list) == 3);
    assert(*sll_get(list, 0) == 30);
    assert(*sll_get(list, 2) == 10);
    sll_free(list);
  }

  {
    SLLNode *list = NULL;

    assert(sll_push(&list, 0, 10));
    assert(sll_push(&list, 0, 20));
    assert(sll_push(&list, 0, 30));

    assert(sll_push(&list, 1, 999));
    assert(sll_push(&list, 4, 40));

    assert(sll_count(list) == 5);

    assert(*sll_get(list, 1) == 999);
    assert(*sll_get(list, 4) == 40);

    sll_free(list);
  }

  {
    SLLNode *list = NULL;

    assert(sll_push(&list, 0, 10));
    assert(sll_push(&list, 0, 20));
    assert(sll_push(&list, 0, 30));
    assert(sll_push(&list, 1, 999));
    assert(sll_push(&list, 4, 40));

    assert(sll_pop(&list, 0));
    assert(sll_pop(&list, 1));
    assert(sll_pop(&list, 2));
    assert(sll_count(list) == 2);

    sll_free(list);
  }

  {
    SLLNode *list = NULL;

    assert(sll_push(&list, 0, 10));
    assert(sll_push(&list, 0, 999));

    assert(!sll_pop(&list, 10));
    assert(sll_get(list, 5) == NULL);

    sll_free(list);
    list = NULL;

    assert(sll_count(list) == 0);
    sll_free(NULL); /* безопасный free NULL */
  }

  printf("single_linked_list.h > all tests passed");
  return 0;
}