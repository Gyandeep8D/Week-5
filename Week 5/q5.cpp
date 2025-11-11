#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Structure for header node
struct Header {
    int count;              // stores the total number of nodes
    struct Node* next;      // pointer to the first actual node
};

struct Header* head = NULL; // pointer to the header node

// Function to create the header node
void createHeader() {
    head = (struct Header*)malloc(sizeof(struct Header));
    if (head == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    head->count = 0;
    head->next = NULL;
    printf("Header node created successfully.\n");
}

// Function to insert a node at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    newNode->data = data;
    newNode->next = NULL;

    if (head->next == NULL) {
        // First node
        head->next = newNode;
    } else {
        struct Node* temp = head->next;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    head->count++; // increase node count
    printf("Node with data %d inserted at the end.\n", data);
}

// Function to delete a node from the beginning
void deleteFromBeginning() {
    if (head->next == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head->next;
    head->next = temp->next;
    printf("Node with data %d deleted from the beginning.\n", temp->data);
    free(temp);

    head->count--; // decrease node count
}

// Function to display the linked list
void displayList() {
    if (head->next == NULL) {
        printf("List is empty.\n");
        printf("Total elements: %d\n", head->count);
        return;
    }

    struct Node* temp = head->next;
    printf("Header Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    printf("Total elements (count in header): %d\n", head->count);
}

// Main function with menu-driven interface
int main() {
    int choice, data;

    createHeader(); // Initialize the header node

    while (1) {
        printf("\n---- Header Linked List Menu ----\n");
        printf("1. Insert Node at End\n");
        printf("2. Delete Node from Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("---------------------------------\n");
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
