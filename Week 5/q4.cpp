#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* head = NULL;

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;

    if (head == NULL) {
        // First node creation
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        struct Node* last = head->prev; // last node before head
        newNode->next = head;          // new node points to head
        head->prev = newNode;          // head's prev points to new node
        newNode->prev = last;          // new node's prev points to last
        last->next = newNode;          // last's next points to new node
    }

    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;

    // If only one node in the list
    if (head->next == head) {
        printf("Node with data %d deleted.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* last = head->prev; // last node
    head = head->next;              // move head to next node
    last->next = head;              // link last node to new head
    head->prev = last;              // link head back to last node

    printf("Node with data %d deleted from the beginning.\n", temp->data);
    free(temp);
}

// Function to display the circular doubly linked list
void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Doubly Linked List: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to head: %d)\n", head->data);
}

// Main function with menu-driven interface
int main() {
    int choice, data;

    while (1) {
        printf("\n---- Circular Doubly Linked List Menu ----\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node from Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("------------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                deleteFromBeginning();
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
