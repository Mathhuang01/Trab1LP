#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void swap(struct Node* a, struct Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

struct Node* partition(struct Node* low, struct Node* high) {
    int pivot = high->data;
    struct Node* i = low->next;

    struct Node* j = low;
    while (j != high) {
        if (j->data < pivot) {
            swap(j, i);
            i = i->next;
        }
        j = j->next;
    }
    swap(i, high);
    return i;
}

void quickSort(struct Node* low, struct Node* high) {
    if (high != NULL && low != high && low != high->next) {
        struct Node* pi = partition(low, high);
        quickSort(low, pi->next);
        quickSort(pi->next, high);
    }
}

struct Node* getLastNode(struct Node* head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;

    push(&head, 4);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    printf("Lista antes da ordenação:\n");
    printList(head);

    struct Node* last = getLastNode(head);
    quickSort(head, last);

    printf("Lista após a ordenação:\n");
    printList(head);

    return 0;
}
