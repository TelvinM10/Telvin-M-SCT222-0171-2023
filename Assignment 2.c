#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to print a linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to merge two sorted linked lists
struct Node* merge(struct Node* listA, struct Node* listB) {
    // Create a dummy node to act as the head of the merged list
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    // Merge the two lists
    while (listA != NULL && listB != NULL) {
        if (listA->data <= listB->data) {
            tail->next = listA;
            listA = listA->next;
        } else {
            tail->next = listB;
            listB = listB->next;
        }
        tail = tail->next;
    }

    // Append the remaining nodes of list1 or list2
    if (listA != NULL) {
        tail->next = listA;
    } else {
        tail->next = listB;
    }

    return dummy.next;
}

int main() {
    // Create two sorted linked lists
    struct Node* listA = createNode(3);
    listA->next = createNode(9);
    listA->next->next = createNode(15);

    struct Node* listB = createNode(6);
    listB->next = createNode(12);
    listB->next->next = createNode(18);

    // Print the original lists
    printf("List A: ");
    printList(listA);
    printf("List B: ");
    printList(listB);

    // Merge the lists
    struct Node* mergedList = merge(listA, listB);

    // Print the merged list
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
