#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct Node* merge(struct Node* listA, struct Node* listB) {
        struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

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

        if (listA != NULL) {
        tail->next = listA;
    } else {
        tail->next = listB;
    }

    return dummy.next;
}

int main() {
    
    struct Node* listA = createNode(3);
    listA->next = createNode(9);
    listA->next->next = createNode(15);

    struct Node* listB = createNode(6);
    listB->next = createNode(12);
    listB->next->next = createNode(18);

    printList(listA);
    printf("List B: ");
    printList(listB);

   
    struct Node* mergedList = merge(listA, listB);

   
    printf("Merged List: ");
    printList(mergedList);

    return 0;
}
