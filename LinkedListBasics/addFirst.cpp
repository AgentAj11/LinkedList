// dynamic list
// add in the front of list


#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
    int data;
    struct Node *next;
};


struct Node* addNode(struct Node* head, int data){

    struct Node* newNode = (Node*) malloc(sizeof(Node));
    newNode -> data = data;

    if(head == NULL){
        newNode -> next = NULL;
    }

    newNode -> next = head;

    head = newNode;

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
    }
}


int main(void){

    struct Node* head = NULL;

    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    head = addNode(head, 50);

    display(head);

    return 0;
}