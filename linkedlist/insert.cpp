#include<iostream>

struct Node{
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next =  nullptr;
    }
};

//Insert 25 at position 3(1-based indexing)
//10 -> 20 -> 30 -> NULL
//10 -> 20 -> 25 -> 30 -> NULL

void insertAtpos(Node* head, int pos,int val){
    
    Node* ptr = head;
    Node* prePtr = ptr;
    int count = 1;

    while(count != pos ){
        prePtr = ptr;
        ptr = ptr->next;
        count++;
    }
    Node* newNode = new Node(val);

    prePtr->next = newNode;
    newNode->next = ptr;
}
int main(){

    Node* node1 = new Node(10);
    
    Node* node2 = new Node(20);
    
    node1->next = node2;
    Node* node3 = new Node(30);
    node2->next = node3;

    Node* head = node1;

    insertAtpos(head, 3,25);

    Node* ptr = head;
    while(ptr!=nullptr){
        std::cout<< ptr->data << "->";
        ptr = ptr->next;
    }
    
    
    
}