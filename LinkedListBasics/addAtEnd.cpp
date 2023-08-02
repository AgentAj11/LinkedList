// dynamic list
// add at the end

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
    }
}


void displayAddress(struct Node* head){
    
    if(head == NULL){
        cout<< "List is empty !";
        return;
    }

    // cout<<"&head = "<<&head;

    while(head){
        
        // this line of code will print the address of pointer (head) not the current node
        // current nodes address will be printed by its previous node (by head -> next)
        // cout<<"\nNode address = " << &head;
        cout<<"\nNode data = " << head -> data;
        cout<<"\nNode next = " << head -> next;
        cout<<endl;
        head = head -> next;
    }
}


int factorial(int n){
    if(n == 1 || n == 0)
        return 1;
    return n * factorial(n - 1);
}


int main(void){

    struct Node* head = NULL;

    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    head = addNode(head, 50);

    display(head);
    
    cout<<endl;

    displayAddress(head);

    return 0;
}