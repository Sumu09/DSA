#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

void PrintLL(Node *ptr) {
    while (ptr != NULL) {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

Node *createLinkedList(int n) {
    Node *head = NULL, *temp = NULL, *newNode = NULL;
    int data, i;

    if (n <= 0) {
        return NULL;
    }

    head = (Node *)malloc(sizeof(Node));
    if (head == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter data for node 1: ");
    scanf("%d", &data);
    head->data = data;
    head->next = NULL;
    temp = head;

    for (i = 2; i <= n; i++) {
        newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL) {
            printf("Memory allocation failed\n");
            exit(1);
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        temp->next = newNode;
        temp = newNode;
    }

    return head;
}

Node *deleteFromBeginning(Node *head) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return head;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node *deleteFromEnd(Node *head) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL) {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

Node *deleteFromPosition(Node *head, int index) {
    if (head == NULL) {
        printf("List is empty. No node to delete.\n");
        return head;
    }
    if (index == 0) {
        return deleteFromBeginning(head);
    }
    Node *p = head;
    Node *q = head->next;
    int i = 0;
    while (i < index - 1 && q->next != NULL) {
        p = p->next;
        q = q->next;
        i++;
    }
    if (i != index - 1 || q == NULL) {
        printf("Index out of bounds.\n");
        return head;
    }
    p->next = q->next;
    free(q);
    return head;
}

int main() {
    Node *head = NULL;
    int n, choice, index;

    printf("Enter the number of nodes in the linked list: ");
    scanf("%d", &n);

    head = createLinkedList(n);

    printf("\nChoose an operation:\n");
    printf("1. Delete from the beginning\n");
    printf("2. Delete from the end\n");
    printf("3. Delete from a specific index\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Linked List before deletion:\n");
    PrintLL(head);

    switch (choice) {
        case 1:
            head = deleteFromBeginning(head);
            break;
        case 2:
            head = deleteFromEnd(head);
            break;
        case 3:
            printf("Enter index to delete: ");
            scanf("%d", &index);
            head = deleteFromPosition(head, index);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Linked List after deletion:\n");
    PrintLL(head);

    return 0;
}
