#include <stdio.h>
#include <stdlib.h>

// Define structure for a polynomial term
struct Term {
    int coeff;
    int exp;
    struct Term* next;
};

// Function to create a new node
struct Term* createNode(int coeff, int exp) {
    struct Term* newNode = (struct Term*)malloc(sizeof(struct Term));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert node in decreasing exponent order
void insertTerm(struct Term** head, int coeff, int exp) {
    struct Term* newNode = createNode(coeff, exp);

    // If list is empty or new exponent is larger than head
    if (*head == NULL || exp > (*head)->exp) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Term* current = *head;
    while (current->next != NULL && current->next->exp >= exp) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
}

// Function to print polynomial
void printPolynomial(struct Term* head) {
    struct Term* temp = head;
    while (temp != NULL) {
        printf("%dx^%d", temp->coeff, temp->exp);
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, coeff, exp;
    struct Term* poly = NULL;

    // Input number of terms
    scanf("%d", &n);

    // Input each term
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }

    // Output polynomial
    printPolynomial(poly);

    return 0;
}
