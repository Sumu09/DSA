#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

Node* deleteFirst(Node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    
    Node* temp = head;
    head = head->next;
    
    if (head != NULL) {
        head->prev = NULL;
    }
    
    free(temp);
    return head;
}

Node* deleteLast(Node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    Node* temp = head;
    
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev == NULL) {
        free(temp);
        return NULL;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }

    if (position < 1) {
        printf("Position should be >= 1\n");
        return head;
    }
    
    Node* temp = head;
    
    if (position == 1) {
        return deleteFirst(head);
    }

    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position is out of bounds.\n");
        return head;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    free(temp);
    return head;
}

int main() {
    Node* head = NULL;
    int choice, data, position, n;
    char continueDeletion;

    printf("Enter the number of nodes to insert initially: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }

    printf("\nInitial Linked List:\n");
    display(head);

    do {
        printf("\nChoose a deletion operation:\n");
        printf("1. Delete the first node\n");
        printf("2. Delete an inner node (specific position)\n");
        printf("3. Delete the last node\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                head = deleteFirst(head);
                break;
            case 2:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
            case 3:
                head = deleteLast(head);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Linked List after deletion:\n");
        display(head);

        printf("\nDo you want to perform another deletion? (y/n): ");
        scanf(" %c", &continueDeletion);

    } while (continueDeletion == 'y' || continueDeletion == 'Y');

    return 0;
}
