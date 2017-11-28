/*
 * use int type to impl hhy linked list
 */

#include <assert.h>
#include <stdlib.h>
#include "hhy_list.h"

hhy_list_t *hhy_list_init() {
    hhy_list_t *list = (hhy_list_t *)malloc(sizeof(hhy_list_t));
    hhy_list_node_t *head = (hhy_list_node_t *)malloc(sizeof(hhy_list_node_t));
    head->data = NULL;
    head->next = NULL;

    list->head = *head;
    list->size = 0;
    return list;
}

size_t hhy_list_size(hhy_list_t *list) {
    return list->size;
}

int hhy_list_empty(hhy_list_t *list) {
    return list->size > 0 ? 1 : 0;
}

void *hhy_list_value_at(hhy_list_t *list, int index) {
    assert(index < list->size);
    hhy_list_node_t *nNode = list->head;
    int i = 0;
    while (nNode->next != NULL) {
        i++;
        nNode = nNode->next;
        if (i == index) {
            return nNode->next->data;
        }
    }
    return NULL;
}

void hhy_list_push_front(hhy_list_t *list, void *value) {
    hhy_list_node_t head = list->head;
    hhy_list_node_t node = (hhy_list_node_t *)malloc(sizeof(hhy_list_node_t));
    node->next = head->next;
    node->data = value;
    head->next = node;
}

void *hhy_list_pop_front(hhy_list_t *list) {
    if (list->size == 0) {
        return NULL;
    }
    hhy_list_node_t head = list->head;
    hhy_list_node_t *dNode = head->next;
    void *dData = dNode->data;
    head->next = dNode->next;
    free(dNode);
    return dData;
}

void hhy_list_push_back(hhy_list_t *list, void *value) {
    hhy_list_node_t node = (hhy_list_node_t *)malloc(sizeof(hhy_list_node_t));
    node->next = NULL;
    node->data = value;
    if (list->size == 0) {
        head->next = node;
        return;
    }
    hhy_list_node_t *nNode = list->head->next;
    while (nNode->next != NULL) {
        nNode = nNode->next;
    }
    nNode->next = node;
}

void *hhy_list_pop_back(hhy_list_t *list) {
    if (list->size == 0) {
        return NULL;
    }

    hhy_list_node_t *nNode = &list->head;
    while (nNode->next->next != NULL) {
        nNode = nNode->next;
    }
    hhy_list_node_t *dNode = nNode->next;
    void *dData = dNode->data;
    nNode->next = NULL;
    free(dNode);
    return dData;
}

void *hhy_list_front(hhy_list_t *list) {
    if (list->size == 0) {
        return NULL;
    }

    return list->head->next->data;
}

void *hhy_list_back(hhy_list_t *list) {
    if (list->size == 0) {
        return NULL;
    }

    hhy_list_node_t *nNode = &list->head;
    while (nNode->next != null) {
        nNode = nNode->next;
    }
    return nNode->data;
}

void hhy_list_insert(hhy_list_t *list, int index, void *value) {
    assert(index < list->size);
    hhy_list_node_t *nNode = &list->head;
    int i = 0;
    while (nNode->next != NULL) {
        if (i == index) {

        }

        nNode = nNode->next;
        i++;
    }
}

void hhy_list_erase(hhy_list_t *list, int index) {
}

void hhy_list_value_n_from_end(hhy_list_t *list, int n) {
}

void hhy_list_reverse(hhy_list_t *list) {
}

void hhy_list_remove_value(hhy_list_t *list, void *value) {
}