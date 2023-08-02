// Merge the already sorted singly linked list

#include <iostream>
#include <stdlib.h>
using namespace std;


struct Node{
    int data;
    struct Node* next;
};


struct Node* createNode(int data){

    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}


struct Node* insertNode(struct Node* head, int data){

    struct Node* newNode = createNode(data);
    
    if(head == NULL){
        head = newNode;
    }   else{
        struct Node* lastNode = head;
        while(lastNode -> next){
            lastNode = lastNode -> next;
        }
        lastNode -> next = newNode;
    }
    return head;
}


void display(struct Node* head){
    while(head){
        cout << head -> data << " --> ";
        head = head -> next;
    }   cout << "NULL";
}


struct Node* merge(struct Node* list1, struct Node* list2) {

    struct Node* list3 = NULL;
    struct Node* tail = NULL; //?

    while (list1 && list2) {
        if (list1->data <= list2->data) {
            if (list3 == NULL) {
                list3 = tail = list1; 
            } else {
                tail->next = list1;
                tail = list1;
            }
            list1 = list1->next;
        } else {
            if (list3 == NULL) {
                list3 = tail = list2;
            } else {
                tail->next = list2;
                tail = list2;
            }
            list2 = list2->next;
        }
    }

    // while merging array two separate loops are required here but not so in case of linked list
    // only one of the two code snippets below runs always
    // since rest of the elements are already linked in chain and in sorted order only one unconnected node has to be connected.
    if (list1) {
        tail->next = list1;
    }

    if (list2) {
        tail->next = list2;
    }

    return list3;
}



int main(void){

    struct Node* list1 = NULL;
    struct Node* list2 = NULL;

    list1 = insertNode(list1, 10);
    list1 = insertNode(list1, 20);
    list1 = insertNode(list1, 30);
    list1 = insertNode(list1, 40);
    list1 = insertNode(list1, 50);
    list1 = insertNode(list1, 60);
    list1 = insertNode(list1, 100);
    list1 = insertNode(list1, 200);
    list1 = insertNode(list1, 230);
    list1 = insertNode(list1, 300);


    list2 = insertNode(list2, 25);
    list2 = insertNode(list2, 35);
   
    list2 = insertNode(list2, 55);
    list2 = insertNode(list2, 75);
    list2 = insertNode(list2, 80);


    cout << "\nList 1 : ";
    display(list1);
    
    cout << "\nList 2 : ";
    display(list2);

    struct Node* mergedList = merge(list1, list2);
    cout << "\nMerged List : ";
    display(mergedList);

    return 0;
}