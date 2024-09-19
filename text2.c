#include <stdio.h>
#include <stdlib.h>

typedef struct list_entry {
    int val;
    struct list_entry *next;
} list_entry;

int main() {
    // Dynamically allocate memory for each node
    list_entry* node1 = (list_entry*)malloc(sizeof(list_entry));
    list_entry* node2 = (list_entry*)malloc(sizeof(list_entry));
    list_entry* node3 = (list_entry*)malloc(sizeof(list_entry));

    // Initialize node values
    node1->val = 3;
    node2->val = 5;
    node3->val = 7;

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL;

    list_entry* head = node1;

    list_entry **pp = &head; /* pointer to a pointer */
    list_entry *entry = head;

    int to_remove = 5;

    while (entry) {
        if (entry->val == to_remove) {
            *pp = entry->next; // remove the entry from the list
            break; // Exit loop after removing the node
        }
        pp = &(entry->next);
        entry = entry->next;
    }

    // Print node addresses
    printf("Node1 Next Addr: %p\n", (void*)node1->next);
    printf("Node3 Addr: %p\n", (void*)node3);

    // Free allocated memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
