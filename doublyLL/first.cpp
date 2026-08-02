#include <iostream>
#include <vector> 
using namespace std;


struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        data= val;
        next = nullptr;
        prev = nullptr;
    }
};


Node* createDLL(vector<int>& arr){
        
   Node* head = new Node(arr[0]);

   Node* ptr = head;

   for(int i =1 ; i <arr.size();i++){
    Node* node = new Node(arr[i]);
    ptr->next = node;
    node->prev = ptr;
    ptr = ptr->next;
   }
return head;
}

void traverseDLL(Node* head){
    if(head == nullptr){
        cout<< "empty linked list ";
    }
    else{
        Node*ptr = head;

        while(ptr != nullptr){
            cout << ptr->data <<"->";
            ptr = ptr->next;
        }
    }
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; 

    Node* head = createDLL(arr);

    traverseDLL(head);
    return 0; 
}