#include "main.h"

int main() {
    LinkedList *my_list = malloc(sizeof(LinkedList));

    printf("%d\n", add(my_list, 15, 2));
    for (int i = 0; i < 30; ++i)
    {
        add_end(my_list, i);
    }

    puts("Add end x30 op: ");
    for (int i = 0; i < my_list->size; ++i)
    {
        printf("%d\n", get(my_list, i));
    }

    printf("remove end: %d\n", remove_end(my_list));
    printf("get last: %d\n", get_last(my_list));
    puts("Re-print list: ");
    for (int i = 0; i < my_list->size; ++i)
    {
        printf("%d\n", get(my_list, i));
    }
    printf("Remove beginning: %d\n", remove_beginning(my_list));
    printf("Get First: %d\n", get_first(my_list));
    puts("Re-print list: ");
    for (int i = 0; i < my_list->size; ++i)
    {
        printf("%d\n", get(my_list, i));
    }

    printf("Remove at 5: %d\n", remove_at(my_list, 5));
    printf("Get at 5: %d\n", get(my_list, 5));
    printf("Add 10 at pos 5 success?: %d\n", add(my_list, 10, 5));
    puts("Re-print list: ");
    for (int i = 0; i < my_list->size; ++i)
    {
        printf("%d\n", get(my_list, i));
    }
    add_beginning(my_list, 15);
    puts("Re-print list after adding 15 to start: ");
    for (int i = 0; i < my_list->size; ++i)
    {
        printf("%d\n", get(my_list, i));
    }
    printf("Destroy list: %d\n", destroy(my_list));


    return 0;
}
