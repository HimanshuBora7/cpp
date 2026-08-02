#include<iostream>


struct Node{
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr; 
    };
};

void insertAtEnd(Node* head , int data){

    Node* node5 = new Node(data);
    Node* ptr = head;

    while(ptr->next != nullptr){
        ptr = ptr->next;
    }
    ptr->next = node5;

}
int main(){
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);

    node1->next = node2;

    Node* node3 = new Node(30);
    node2->next = node3;

    Node* head = node1;

    
    Node* node4 = new Node(5);
    node4->next = head;
    head = node4;
    Node* ptr = head;

    insertAtEnd(head,40);
    
    while(ptr != nullptr){

        std::cout<< ptr->data << "->";
        
        ptr = ptr->next;
    }
}