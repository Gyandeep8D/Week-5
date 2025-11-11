#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL; // Points to the last node in the circular linked list

// Function to insert a node at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;

    if (last == NULL) {
        // First node in the list
        newNode->next = newNode;
        last = newNode;
    } else {
        newNode->next = last->next; // New node points to the first node
        last->next = newNode;       // Last node points to new first node
    }

    printf("Node with data %d inserted at the beginning.\n", data);
}

// Function to delete a node from the end
void deleteFromEnd() {
    if (last == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = last->next; // Start from the first node

    // If only one node in the list
    if (last->next == last) {
        printf("Node with data %d deleted.\n", last->data);
        free(last);
        last = NULL;
        return;
    }

    // Traverse to the second last node
    while (temp->next != last)
        temp = temp->next;

    printf("Node with data %d deleted from the end.\n", last->data);
    temp->next = last->next; // Second last node points to first node
    free(last);
    last = temp; // Update last pointer
}

// Function to display the circular linked list
void displayList() {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = last->next; // Start from the first node
    printf("Circular Linked List: ");

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);

    printf("(back to %d)\n", last->next->data);
}

// Main function with menu-driven interface
int main() {
    int choice, data;

    while (1) {
        printf("\n---- Circular Linked List Menu ----\n");
        printf("1. Insert Node at Beginning\n");
        printf("2. Delete Node from End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                deleteFromEnd();
                break;
            case 3:
                displayList();
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
