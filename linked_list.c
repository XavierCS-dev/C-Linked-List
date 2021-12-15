//
// Created by xavier on 15/12/2021.
//
#include "linked_list.h"


typedef struct LinkedNode_x {

    LinkedNode *prev_node;
    LinkedNode *next_node;
    int data;
} LinkedNode;

void add_to_empty(LinkedList *list, int x)
{
    list->first_node = malloc(sizeof(LinkedNode));
    list->last_node = list->first_node;
    list->first_node->data = x;
    // currently first and last node point to the same object, so val should be assigned for both of them.
    list->first_node->prev_node = list->last_node;
    list->first_node->next_node = list -> last_node;
    list->size = 1;
}

LinkedNode* traverse(LinkedList *list, int pos)
{
    if (is_empty(list)) return NULL;
    if (pos >= list->size) return NULL;
    LinkedNode *curr_node = list->first_node;
    for (int i = 0; i < pos; ++i)
    {
        curr_node = curr_node->next_node;
    }
    return curr_node;
}

void add_end(LinkedList *list, int x)
{
    if (is_empty(list))
    {
        add_to_empty(list, x);
        return;
    }
    LinkedNode *new_node = malloc(sizeof(LinkedNode));
    new_node->data = x;
    new_node->prev_node = list->last_node;
    new_node->next_node = list->first_node;
    list->last_node->next_node = new_node;
    list->first_node->prev_node = new_node;
    list->last_node = new_node;
    ++list->size;
}

int remove_end(LinkedList *list)
{
    if(is_empty(list)) return INT_MIN;
    if (list->size == 1)
    {
        int return_data =  list->first_node->data;
        list->first_node = NULL;
        list->last_node = NULL;
        return return_data;
    }
    LinkedNode *removed_node = list->last_node;
    list->last_node->prev_node->next_node = list->first_node;
    list->first_node->prev_node = list->last_node->prev_node;
    list->last_node = list->last_node->prev_node;
    int return_data = removed_node->data;
    free(removed_node);
    --list->size;
    return return_data;
}

void add_beginning(LinkedList *list, int x)
{
    if (is_empty(list))
    {
        add_to_empty(list, x);
        return;
    }
    LinkedNode *new_node = malloc(sizeof(LinkedNode));
    list->first_node->prev_node = new_node;
    list->last_node->next_node = new_node;
    new_node->prev_node = list->last_node;
    new_node->next_node = list->first_node;
    list->first_node = new_node;
    new_node->data = x;
    ++list->size;
}

int remove_beginning(LinkedList *list)
{
    if (is_empty(list)) return INT_MIN;
    if (list->size == 1)
    {
        int return_data =  list->first_node->data;
        list->first_node = NULL;
        list->last_node = NULL;
        return return_data;
    }
    LinkedNode *removed_node = list->first_node;
    list->last_node->next_node = list->first_node->next_node;
    list->first_node->next_node->prev_node = list->last_node;
    list->first_node = list->first_node->next_node;
    int return_data = removed_node->data;
    free(removed_node);
    --list->size;
    return return_data;
}

int add(LinkedList *list, int x, int pos)
{
    LinkedNode *curr_node = traverse(list, pos);
    if (curr_node == NULL) return -1;
    LinkedNode *new_node = malloc(sizeof(LinkedNode));
    new_node->prev_node = curr_node->prev_node;
    new_node->next_node = curr_node;
    curr_node->prev_node->next_node = new_node;
    curr_node->prev_node = new_node;
    new_node->data = x;
    ++list->size;
    return 0;
}

int remove_at(LinkedList *list, int pos)
{
    LinkedNode *curr_node = traverse(list, pos);
    if (curr_node == NULL) return INT_MIN;
    if (list->size == 1)
    {
        int return_data =  list->first_node->data;
        list->first_node = NULL;
        list->last_node = NULL;
        return return_data;
    }
    curr_node->prev_node->next_node = curr_node->next_node;
    curr_node->next_node->prev_node = curr_node->prev_node;
    int return_data = curr_node->data;
    free(curr_node);
    --list->size;
    return return_data;
}

int destroy(LinkedList *list)
{
    LinkedNode *pointers[list->size];
    if (is_empty(list)) return -1;
    LinkedNode *curr_node = list->first_node;
    for (int i = 0; i < list->size; ++i)
    {
        pointers[i] = curr_node->next_node;
    }
    for (int i = list->size - 1; i <= 0; --i)
    {
        free(pointers[i]);
    }
    list->first_node = NULL;
    list->last_node = NULL;
    list->size = 0;
    return 0;
}

int get(LinkedList *list, int pos)
{
    return traverse(list, pos)->data;
}

int get_last(LinkedList *list)
{
    return list->last_node->data;
}

int get_first(LinkedList *list)
{
    return list->first_node->data;
}

_Bool is_empty(LinkedList *list)
{
    return list->size == 0;
}



