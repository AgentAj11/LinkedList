// insertion sort
// on linked list
// possibly only on doubly linked list


#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> prev = NULL;
    newNode -> next = NULL;

    return newNode;
}


struct Node* addNode(struct Node* head, int data){
    
    struct Node* newNode = createNode(data);

    if(head == NULL){
        head = newNode;
    }   else{

        struct Node* lastNode = head;

        while(lastNode -> next){
            lastNode = lastNode -> next;
        }

        lastNode -> next = newNode;
        newNode -> prev = lastNode;
    }

    return head;
}


void display(struct Node* head){

    if(head == NULL)
        return;
    
    while(head){
        
        cout << head -> data << " --> ";
        head = head -> next;
    }   cout << "NULL";
}

void sortList(struct Node* head) {
    if (head == NULL || head -> next == NULL)
        return;

    struct Node* current = head -> next;

    while (current) {

        int key = current -> data;
        struct Node* prevNode = current -> prev;

        while (prevNode && prevNode -> data > key) {
            prevNode -> next -> data = prevNode -> data;
            prevNode = prevNode -> prev;
        }

        if (prevNode == NULL)
            head -> data = key;
        else
            prevNode -> next -> data = key;

        current = current -> next;
    }
}



int main(void){

    struct Node* head = NULL;

    head = addNode(head, 10);
    head = addNode(head, 23);
    head = addNode(head, 3);
    head = addNode(head, 60);
    head = addNode(head, 13);
    head = addNode(head, -87);
    head = addNode(head, 07);
    head = addNode(head, 54);
    head = addNode(head, 33);
    head = addNode(head, 123);
    head = addNode(head, 982);
    head = addNode(head, -787);
    head = addNode(head, 76);
    head = addNode(head, 23);
    head = addNode(head, 51);


    cout << "\nUnsorted List : ";
    display(head);

    cout << "\nSorted List : ";
    sortList(head);
    display(head);

    return 0;
}