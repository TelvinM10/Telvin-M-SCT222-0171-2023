#include <stdio.h>
#include <stdlib.h>

// Definition of a node in a doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to append a node to the end of the doubly linked list
void append(Node** headRef, int data) {
    Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }

    Node* current = *headRef;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

// Function to print a doubly linked list
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to reverse a doubly linked list
Node* reverseList(Node* head) {
    Node* temp = NULL;
    Node* current = head;

    // Swap next and prev for all nodes
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Adjust head to point to the new first node
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

// Function to add two numbers represented by doubly linked lists
Node* addNumbers(Node* listA, Node* listB) {
    // Reverse both lists to make addition easier
    listA = reverseList(listA);
    listB = reverseList(listB);

    Node* result = NULL;
    int carry = 0;

    // Add corresponding digits of both lists
    while (listA != NULL || listB != NULL || carry != 0) {
        int sum = carry;

        if (listA != NULL) {
            sum += listA->data;
            listA = listA->next;
        }

        if (listB != NULL) {
            sum += listB->data;
            listB = listB->next;
        }

        carry = sum / 10;
        append(&result, sum % 10);
    }

    // Reverse the result list to restore correct order
    result = reverseList(result);
    return result;
}

int main() {
    Node* listA = NULL;
    Node* listB = NULL;

    // Creating the first number as a doubly linked list 
    append(&listA, 2);
    append(&listA, 5);
    append(&listA, 8);

    // Creating the second number as a doubly linked list 
    append(&listB, 5);
    append(&listB, 7);
    append(&listB, 9);

    // Printing the numbers
    printf("First Number: ");
    printList(listA);

    printf("Second Number: ");
    printList(listB);

    // Adding the two numbers
    Node* result = addNumbers(listA, listB);

    // Printing the result
    printf("Sum: ");
    printList(result);

    // Freeing memory
    Node* temp;
    while (listA != NULL) {
        temp = listA;
        listA = listA->next;
        free(temp);
    }

    while (listB != NULL) {
        temp = listB;
        listB = listB->next;
        free(temp);
    }

    while (result != NULL) {
        temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
