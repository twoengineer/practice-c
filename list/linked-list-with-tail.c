#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

typedef struct {
  linked_node *next;
  void data;
} linked_node;

typedef struct {
  linked_node head;
  linked_node tail;
  size_t size;
} linked_list_with_tail;


linked_list_with_tail * initLinkedList() {
  linked_list_with_tail *l = (struct linked_list_with_tail *)malloc(sizeof(struct linked_list_with_tail));
  if (l == NULL) {
    return NULL;
  }

  linked_node *head = (struct linked_node *)malloc(sizeof(struct linked_node));
  if (head == NULL) {
    return NULL;
  }

  linked_node *tail = (struct linked_node *)malloc(sizeof(struct linked_node));
  if (tail == NULL) {
    return NULL;
  }

  head->next = NULL;
  head->data = NULL;
  tail->next = NULL;
  tail->data = NULL;
  l->head = *head;
  l->tail = *tail;
  l->size = 0;
}

size_t size(linked_list_with_tail *l) {
  return l->size;
}

bool empty(linked_list_with_tail *l) {
  if (l->head->next == NULL && l->size = 0) {
    return true;
  }
  return false;
}

void * value_at(linked_list_with_tail *l, int index) {
  linked_node *p = &l->head;
  int i = 0;
  while(p->next != null) {
    if (i == index) {
      return p->data;
    }
    p = p->next;
    i++;
  }
  return NULL;
}

void push_front(linked_list_with_tail *l, void *value) {
  linked_node head = l->head;
  linked_node *v = (struct linked_node *)malloc(sizeof(struct linked_node));
  v->data = value;
  v->next = head->next;
  head->next = v;
  if (l->tail->next = NULL) {
    l->tail->next = v;
  }
  l->size++;
}

void *pop_front(linked_list_with_tail *l) {
  linked_node head = l->head;
  linked_node *p = l->head->next;
  l->head->next = p->next;
  void *data = p->data;
  free(p);
  l->size--;
  if (l->size == 0) {
    l->tail->next = NULL;
  }
  return data;
}

void push_back(linked_list_with_tail *l, void *value) {
  linked_node *v = (struct linked_node *)malloc(sizeof(struct linked_node));
  v->next = NULL;
  v->data = value;

  linked_node *p = &l->head;
  while(p->next != NULL) {
    p = p->next;
  }
  p->next = v;
  l->tail->next = v;
  l->size++;
}

void * pop_back(linked_list_with_tail *l) {
  linked_node *p = &l->head;
  while(p->next->next != NULL) {
    p = p->next;
  }

  linked_node *t = p->next;
  void *data = t->data;
  p->next = NULL;
  l->tail->next = p;
  free(t);
  l->size--;
  return data;
}

void * front(linked_list_with_tail *l) {
  linked_node *p = l->head->next;
  return p->data;
}

void * back(linked_list_with_tail *l) {
  linked_node *p = &l->tail->next;
  return p->data;
}

TODO// add tail handler

void * insert(linked_list_with_tail *l, int index, void *value) {
  linked_node *p = &l->head;
  int i = 0;
  while (p->next != NULL) {
    if (i == index - 1) {
      linked_node *v = (struct linked_node *)malloc(sizeof(struct linked_node));
      v->value = value;
      v->next = p->next;
      p->next = v;
      l->size++;
    }
    p = p->next;
    i++;
  }
}

void * erase(linked_list_with_tail *l, int index) {
  assert(index < l->size);
  linked_node *p = &l->head;
  int i = 0;
  while(p->next != NULL) {
    if (i == index -1) {
      linked_node *e = p->next;
      p->next = p->next->next;
      return e->data;
    }
    p = p->next;
    i++;
  }
}

void * value_n_from_end(linked_list_with_tail *l, int n) {
  assert(n < l->size);
  int index = l->size - n;
  linked_node *p = &l->head;
  int i = 0;
  while(p->next != NULL) {
    if (i == index) {
      return p->data;
    }
    p = p->next;
    i++;
  }
}

void * pop_back(linked_list_with_tail *l) {
  linked_node *p = &l->head;
  while(p->next->next != NULL) {
    p = p->next;
  }

  linked_node *t = p->next;
  void *data = t->data;
  free(t);
  l->size--;
  return data;
}

void reverse(linked_list_with_tail *l) {
  size_t a = l->size;
  while (a > 0) {
    void *data = pop_back(l);
    push_front(l, data);
    a --;
  }
}

void * remove_value(linked_list_with_tail *l, void *value) {
  linked_node *p = &l->head;
  while (p->next->next != NULL) {
    if (*p->next->data == *value) {
      linked_node *t = p->next;
      p->next = p->next->next;
      free(t);
      break;
    }
  }
}

int main(int argc, char **argv) {
  struct rlimit res = { .rlim_cur = RLIM_INFINITY, .rlim_max = RLIM_INFINITY };
  setrlimit(RLIMIT_CORE, &res);
}
