#ifndef PRACTICE_C_HHY_LIST_H__
#define PRACTICE_C_HHY_LIST_H__

typedef struct {
  hhy_list_node_t *next;
  void *data;
} hhy_list_node_t;

typedef struct {
  hhy_list_node_t head;
  size_t size;
} hhy_list_t;

hhy_list_t *hhy_list_init();
size_t hhy_list_size(hhy_list_t *list);
int hhy_list_empty(hhy_list_t *list);
void *hhy_list_value_at(hhy_list_t *list, int index);
void hhy_list_push_front(hhy_list_t *list, void *value);
void *hhy_list_pop_front(hhy_list_t *list);
void hhy_list_push_back(hhy_list_t *list, void *value);
void *hhy_list_pop_back(hhy_list_t *list);
void *hhy_list_front(hhy_list_t *list);
void *hhy_list_back(hhy_list_t *list);
void hhy_list_insert(hhy_list_t *list, int index, void *value); // 插入值到指定的索引，并把当前索引的元素指向到新的元素
void hhy_list_erase(hhy_list_t *list, int index); // 删除指定索引的节点
void hhy_list_value_n_from_end(hhy_list_t *list, int n); // 返回倒数第 n 个节点的值
void hhy_list_reverse(hhy_list_t *list); // 逆序链表
void hhy_list_remove_value(hhy_list_t *list, void *value); // 删除链表中指定值的第一个元素

#endif