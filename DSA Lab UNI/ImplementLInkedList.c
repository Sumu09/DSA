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

Node *insertAtFirst(Node *head, int data) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

Node *insertAtIndex(Node *head, int data, int index) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;

    int i = 0;
    while (i != (index - 1)) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

Node *insertAtEnd(Node *head, int data) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    Node *p = head;
    ptr->data = data;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

Node *insertAfterNode(Node *head, Node *prevNode, int data) {
    Node *ptr = (Node *)malloc(sizeof(Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

int main() {
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head = (Node *)malloc(sizeof(Node));
    second = (Node *)malloc(sizeof(Node));
    third = (Node *)malloc(sizeof(Node));
    fourth = (Node *)malloc(sizeof(Node));

    head->data = 10;
    head->next = second;

    second->data = 30;
    second->next = third;

    third->data = 40;
    third->next = fourth;

    fourth->data = 50;
    fourth->next = NULL;

    int choice, data, index;
    printf("\nChoose an operation:\n");
    printf("1. Insert at the beginning\n");
    printf("2. Insert at a specific index\n");
    printf("3. Insert at the end\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);


    switch (choice) {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            printf("Linked List before any insertion:\n");
            PrintLL(head);
            head = insertAtFirst(head, data);
            break;
        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter index to insert at: ");
            scanf("%d", &index);
            printf("Linked List before any insertion:\n");
            PrintLL(head);
            head = insertAtIndex(head, data, index);
            break;
        case 3:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            printf("Linked List before any insertion:\n");
            PrintLL(head);
            head = insertAtEnd(head, data);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Linked List afte the insertion:\n");
    PrintLL(head);

    return 0;
}
