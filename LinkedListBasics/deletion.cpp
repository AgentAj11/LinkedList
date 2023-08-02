// delete the specified node from list

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


struct Node* deleteNode(struct Node *head, int key){

    struct Node* targetNode = head;

    if(head -> data == key){
        
        head = head -> next;
        free(targetNode);
    } else{
        
        struct Node* current = head;
        
        while(current -> next && current -> next -> data != key){

            current = current -> next;
        }

        // when control reaches here it means either the target node has been found or entire list has been traversed.
        if(current -> next){

            targetNode = current -> next;
            current -> next = current -> next -> next;
            free(targetNode);
        }

        else{

            cout << "\nTarget node not found !\n";
        }
    }

    return head;
}


int main(void){


    struct Node* head = NULL;

    head = addNode(head, 10);
    head = addNode(head, 20);
    head = addNode(head, 30);
    head = addNode(head, 40);
    head = addNode(head, 50);
    head = addNode(head, 60);

    cout<< "\nOriginal List : ";

    display(head);

    int key;
    cout << "\nEnter Key : ";
    cin>>key;
    
    head = deleteNode(head, key);

    cout << "\nList after deleting " << key << "\n";
    display(head);

    return 0;
}

