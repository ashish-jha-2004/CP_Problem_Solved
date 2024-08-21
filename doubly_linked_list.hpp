#include <iostream>
using namespace std;

#define PUSH_BACK 1
#define PUSH_FRONT 2
#define DELETE 3
#define DISPLAY 4
#define EXIT 5

class Node {
public:
    int data;
    Node* next, *prev;
};

class CircularLinkedList {
public:
    Node* head, *tail;

    CircularLinkedList() {
        head = nullptr;
        tail = head;
    }

    void push_back(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (head == nullptr) {
            head = newNode;
            tail = newNode; 
            newNode->next = head;
            newNode->prev = tail;
        } else {
            head->prev = newNode;
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
            newNode->next = head;
        }
    }

    void push_front(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        if (head == nullptr) {
            head = newNode;
            tail = head;
            newNode->next = head;
            newNode->prev = tail;
        } else {
            head->prev = newNode;
            tail->next = newNode;
            newNode->next = head;
            newNode->prev = tail;
            head = newNode;
        }
    }

    void display() {
        Node* temp = head;
        if (head == nullptr){
            cout << endl;
            return;
        }
        while (temp->next != tail) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        temp = temp -> next;
        cout << temp->data << endl;
    }

    void deleteNode(int data) {
        Node* temp = head;
        if (head==tail) {
            if (head != NULL and head->data==data) {
                delete head;
                head=nullptr;
                tail=nullptr;
            }
            return;
        }
        else {
            while (temp != tail) {
                if (temp != NULL and temp->data == data) {
                    if (temp == head) {
                        head = temp->next;
                    }
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;                    
                    delete temp;
                    return;
                }
                temp = temp->next;
            }
            if (temp != NULL and temp->data == data) {
                tail = temp->prev;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                return;
            }
        }
    }
};

int main() {
    CircularLinkedList list;
    int choice, data;
    while (1) {
        cin >> choice;
        switch (choice) {
            case PUSH_FRONT:
                cin >> data;
                list.push_front(data);
                break;
            case PUSH_BACK:
                cin >> data;
                list.push_back(data);
                break;
            case DELETE:
                cin >> data;
                list.deleteNode(data);
                break;
            case DISPLAY:
                list.display();
                break;
            case EXIT:
                return 0;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}