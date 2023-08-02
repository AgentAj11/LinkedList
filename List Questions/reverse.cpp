// reversing the linked list
// doubly linked list is simple to reverse due to presence of prev pointer in it
// we can have two pointers one in the begining of the list and other at the end of the list
// and simply reverse the list as an array is reversed

// Reversal in Sinlgy linked list : just reverse the links


#include <iostream>
#include <stdlib.h>

using namespace std;


struct Node{
    int data;
    struct Node* next;
};


struct Node* addNode(struct Node* head, int data){

    struct Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL;

    if(head == NULL){
        head = newNode;
    }
    else{

        struct Node* lastNode = head;

        while(lastNode -> next){
            lastNode = lastNode -> next;
        }

        lastNode -> next = newNode;
    }

    return head;
}


void display(struct Node* head){

    if(head == NULL){
        cout<< "List is empty !";
        return;
    }

    while(head){
        cout<< head -> data << " --> ";
        head = head -> next;
    }   cout << "NULL";
}


struct Node* reverse(struct Node* current){

    if(current == NULL || current->next == NULL){
        return current;
    }
    
    struct Node* newHead = reverse(current->next);

    current->next->next = current;
    current->next = NULL;

    return newHead;
}


int main(void){

    struct Node* head = NULL;

    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    head = addNode(head, 50);

    cout << "\nOriginal List : ";
    display(head);
    cout << endl;

    cout << "\nReversed List : ";
    head = reverse(head);
    display(head);
    cout << endl;

    return 0;
}