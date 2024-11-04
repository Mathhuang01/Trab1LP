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

struct Node* getMiddle(struct Node* head) {
    if (head == NULL) return head;

    struct Node* slow = head;
    struct Node* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct Node* sortedMerge(struct Node* left, struct Node* right) {
    if (left == NULL) return right;
    if (right == NULL) return left;

    struct Node* result = NULL;

    if (left->data <= right->data) {
        result = left;
        result->next = sortedMerge(left->next, right);
    } else {
        result = right;
        result->next = sortedMerge(left, right->next);
    }
    return result;
}

void mergeSort(struct Node** head_ref) {
    if (*head_ref == NULL || (*head_ref)->next == NULL) return;

    struct Node* middle = getMiddle(*head_ref);
    struct Node* next_of_middle = middle->next;

    middle->next = NULL;

    mergeSort(head_ref);
    mergeSort(&next_of_middle);

    *head_ref = sortedMerge(*head_ref, next_of_middle);
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

    // Inserindo dados na lista
    push(&head, 15);
    push(&head, 10);
    push(&head, 5);
    push(&head, 20);
    push(&head, 3);
    push(&head, 2);

    printf("Lista antes da ordenação:\n");
    printList(head);

    mergeSort(&head);

    printf("Lista após a ordenação:\n");
    printList(head);

    return 0;
}
