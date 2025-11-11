#include <stdio.h>
#include <stdlib.h>

// Structure for a polynomial term
struct Node {
    int coeff;              // Coefficient
    int exp;                // Exponent
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int coeff, int exp) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node in descending order of exponents
struct Node* insertNode(struct Node* head, int coeff, int exp) {
    struct Node* newNode = createNode(coeff, exp);

    // If list is empty or new node has higher exponent
    if (head == NULL || exp > head->exp) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL && temp->next->exp >= exp)
            temp = temp->next;

        // If same exponent, add coefficients
        if (temp->exp == exp)
            temp->coeff += coeff;
        else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    return head;
}

// Function to display a polynomial
void displayPoly(struct Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        temp = temp->next;
        if (temp != NULL)
            printf(" + ");
    }
    printf("\n");
}

// Function to add two polynomials
struct Node* addPoly(struct Node* poly1, struct Node* poly2) {
    struct Node *result = NULL, *temp1 = poly1, *temp2 = poly2;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->exp == temp2->exp) {
            int sumCoeff = temp1->coeff + temp2->coeff;
            if (sumCoeff != 0)
                result = insertNode(result, sumCoeff, temp1->exp);
            temp1 = temp1->next;
            temp2 = temp2->next;
        } else if (temp1->exp > temp2->exp) {
            result = insertNode(result, temp1->coeff, temp1->exp);
            temp1 = temp1->next;
        } else {
            result = insertNode(result, temp2->coeff, temp2->exp);
            temp2 = temp2->next;
        }
    }

    // Add remaining terms
    while (temp1 != NULL) {
        result = insertNode(result, temp1->coeff, temp1->exp);
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        result = insertNode(result, temp2->coeff, temp2->exp);
        temp2 = temp2->next;
    }

    return result;
}

// Function to create a polynomial from user input
struct Node* createPolynomial() {
    struct Node* poly = NULL;
    int n, coeff, exp;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        poly = insertNode(poly, coeff, exp);
    }

    return poly;
}

// Main function
int main() {
    struct Node *poly1 = NULL, *poly2 = NULL, *sum = NULL;

    printf("\nEnter first polynomial:\n");
    poly1 = createPolynomial();

    printf("\nEnter second polynomial:\n");
    poly2 = createPolynomial();

    printf("\nFirst Polynomial: ");
    displayPoly(poly1);

    printf("Second Polynomial: ");
    displayPoly(poly2);

    sum = addPoly(poly1, poly2);

    printf("\nResultant Polynomial after Addition: ");
    displayPoly(sum);

    return 0;
}
