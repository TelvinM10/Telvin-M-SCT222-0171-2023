#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

typedef struct Node Node;

    Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

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

    void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

   Node* reverseList(Node* head) {
    Node* temp = NULL;
    Node* current = head;

       while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

        if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}

Node* addNumbers(Node* listA, Node* listB) {
    
    listA = reverseList(listA);
    listB = reverseList(listB);

    Node* result = NULL;
    int carry = 0;

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

    
    result = reverseList(result);
    return result;
}

    int main() {
    Node* listA = NULL;
    Node* listB = NULL;

     
    append(&listA, 2);
    append(&listA, 5);
    append(&listA, 8);

     
    append(&listB, 5);
    append(&listB, 7);
    append(&listB, 9);

    printf("First Number: ");
    printList(listA);

    printf("Second Number: ");
    printList(listB);

    Node* result = addNumbers(listA, listB);

    printf("Sum: ");
    printList(result);

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
