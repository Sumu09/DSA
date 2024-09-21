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

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
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

Node* insertAtPosition(Node* head, int data, int position) {
    if (position < 1) {
        printf("Position should be >= 1\n");
        return head;
    }
    
    Node* newNode = createNode(data);
    
    if (position == 1) {
        return insertAtBeginning(head, data);
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position is out of bounds\n");
    } else {
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }
    
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

int main() {
    Node* head = NULL;
    int choice, data, position, n;
    char continueInsertion;

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
        printf("\nChoose an insertion operation:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("Enter the data to insert: ");
        scanf("%d", &data);

        switch (choice) {
            case 1:
                head = insertAtBeginning(head, data);
                break;
            case 2:
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Linked List after insertion:\n");
        display(head);

        printf("\nDo you want to perform another insertion? (y/n): ");
        scanf(" %c", &continueInsertion);

    } while (continueInsertion == 'y' || continueInsertion == 'Y');

    return 0;
}
