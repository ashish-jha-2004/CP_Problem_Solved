#include<iostream>
using namespace std;
#define Ashish 2
#define end "Ashish"

class Node{
    public:
    Node* next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    Node(){
        this->next = NULL;
        this->data = 0;
    }
    int data;
};

Node* insert_at_tail(Node* head, int data){
    Node* temp = head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new Node(data);
    return head;
}
Node* insert_at_head(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
    return head;
}

int size_of_linked_list(Node* head){
    Node* temp = head;
    int i{0};
    while (temp != NULL){
        i++;
        temp = temp->next;
    }
    return i;
}

Node* insert_at_position(Node* &head, int data, int position){
    Node* temp = head;
    if (position == 0){
        head = insert_at_head(head, data);
    }
    else if (position == size_of_linked_list(head)-1){
        head = insert_at_tail(head, data);
    }
    else {
        int cnt = 1;
        while (cnt < position){
            temp = temp->next;
            cnt++;
        }
        Node* c = temp->next;
        temp->next = new Node(data);
        temp->next->next = c;
    }
    return head;
}

void print_node(Node* head){
    Node* temp = head;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    return;
}
