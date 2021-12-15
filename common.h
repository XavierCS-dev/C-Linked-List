//
// Created by xavier on 15/12/2021.
//

#ifndef LINKEDLIST_COMMON_H
#define LINKEDLIST_COMMON_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>



typedef struct LinkedNode_x LinkedNode;
typedef struct LinkedList_x {

    LinkedNode *first_node;
    LinkedNode *last_node;
    int size;

} LinkedList;
void add_end(LinkedList *list, int x);
int remove_end(LinkedList *list);
void add_beginning(LinkedList *list, int x);
int remove_beginning(LinkedList *list);

// return 0 for success
// return -1 for failure
int add(LinkedList *list, int x, int pos);

// return INT_MIN if pos is invalid
int remove_at(LinkedList *list, int pos);

// return 0 success, -1 failure
int destroy(LinkedList *list);
int get(LinkedList *list, int pos);
int get_last(LinkedList *list);
int get_first(LinkedList *list);
_Bool is_empty(LinkedList *list);


#endif //LINKEDLIST_COMMON_H
