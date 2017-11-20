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
  size_t size;
} linked_list;


linked_list * initLinkedList() {
  linked_list *l = (struct linked_list *)malloc(sizeof(struct linked_list));
  if (l == NULL) {
    return NULL;
  }

  linked_node *head = (struct linked_node *)malloc(sizeof(struct linked_node));
  if (head == NULL) {
    return NULL;
  }

  head->next = NULL;
  head->data = NULL;
  l->head = *head;
  l->size = 0;
}

size_t size(linked_list *l) {
  return l->size;
}

bool empty(linked_list *l) {
  if (l->head->next == NULL && l->size = 0) {
    return true;
  }
  return false;
}

void * value_at(linked_list *l, int index) {
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

void push_front(linked_list *l, void *value) {
  linked_node head = l->head;
  linked_node *v = (struct linked_node *)malloc(sizeof(struct linked_node));
  v->data = value;
  v->next = head->next;
  head->next = v;
  l->size++;
}

void *pop_front(linked_list *l) {
  linked_node head = l->head;
  linked_node *p = l->head->next;
  l->head->next = p->next;
  void *data = p->data;
  free(p);
  l->size--;
  return data;
}

void push_back(linked_list *l, void *value) {
  linked_node *v = (struct linked_node *)malloc(sizeof(struct linked_node));
  v->next = NULL;
  v->data = value;

  linked_node *p = &l->head;
  while(p->next != NULL) {
    p = p->next;
  }
  p->next = v;
  l->size++;
}

void * pop_back(linked_list *l) {
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

void * front(linked_list *l) {
  linked_node *p = l->head->next;
  return p->data;
}

void * back(linked_list *l) {
  linked_node *p = &l->head;
  while (p->next != NULL) {
    p = p->next;
  }
  return p->data;
}

void * insert(linked_list *l, int index, void *value) {
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

void * erase(linked_list *l, int index) {
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

void * value_n_from_end(linked_list *l, int n) {
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

void * pop_back(linked_list *l) {
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

void reverse(linked_list *l) {
  size_t a = l->size;
  while (a > 0) {
    void *data = pop_back(l);
    push_front(l, data);
    a --;
  }
}

void * remove_value(linked_list *l, void *value) {
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

/*
size() —— 返回链表中数据元素的个数
empty() —— 若链表为空则返回一个布尔值 true
value_at(index) —— 返回第 n 个元素的值（从0开始计算）
push_front(value) —— 添加元素到链表的首部
pop_front() —— 删除首部元素并返回其值
push_back(value) —— 添加元素到链表的尾部
pop_back() —— 删除尾部元素并返回其值
front() —— 返回首部元素的值
back() —— 返回尾部元素的值
insert(index, value) —— 插入值到指定的索引，并把当前索引的元素指向到新的元素
erase(index) —— 删除指定索引的节点
value_n_from_end(n) —— 返回倒数第 n 个节点的值
reverse() —— 逆序链表
remove_value(value) —— 删除链表中指定值的第一个元素
*/
