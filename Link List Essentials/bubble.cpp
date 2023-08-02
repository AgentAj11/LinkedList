// bubble sort in singly linked linear list


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
    }   cout << "NULL" << endl;
}


int listLength(struct Node* head){
    
    int length = 0;
    while(head){
        head = head -> next;
        length++;
    }

    return length;
}


void sortList(struct Node* head){

    int N = listLength(head);

    for(int i = 1; i < N; i++){

        struct Node* currentNode = head;

        while(currentNode -> next){

            if(currentNode -> data > currentNode -> next -> data){
                swap(currentNode -> data, currentNode -> next -> data);
            }

            currentNode = currentNode -> next;
        }
    }
}


int main(void){

    struct Node* head = NULL;

    head = addNode(head, 30);
    head = addNode(head, 02);
    head = addNode(head, 93);
    head = addNode(head, -23);
    head = addNode(head, 52);
    head = addNode(head, 123);
    head = addNode(head, 652);
    head = addNode(head, 72);
    head = addNode(head, 12);




    cout << "\nUnsorted List : ";
    display(head);
    
    cout << "\n\nSorted List : ";
    sortList(head);
    display(head);

    return 0;
}