#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node() {
        this->data = 0;
        this->next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    void insert_at_head(Node* &head, int data) {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        temp = NULL;
    }

    void print(Node* &head) {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
};