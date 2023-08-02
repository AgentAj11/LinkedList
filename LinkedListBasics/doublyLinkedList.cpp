// doubly linked list
// linear

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    return newNode;
}


struct Node* addNode(struct Node* head, int data) {

    struct Node* newNode = createNode(data);

    if (!head) {
        head = newNode;
    } else {

        struct Node* lastNode = head;

        while (lastNode -> next) {
            lastNode = lastNode -> next;
        }
        
        lastNode -> next = newNode;
        newNode -> prev = lastNode;
    }
    return head;
}


void display(struct Node* head) {

    if(!head)
        return;
    
    while (head) {
        printf("%d --> ", head -> data);
        head = head -> next;
    }
    printf("NULL");
}

int main() {
    struct Node* head = NULL;

    // Add nodes to the doubly linked list
    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    head = addNode(head, 50);

    // Display the doubly linked list
    display(head);

    return 0;
}
