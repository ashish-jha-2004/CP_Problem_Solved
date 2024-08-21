#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class CircularDoublyLinkedList {
public:
    Node* head;

    CircularDoublyLinkedList() {
        head = nullptr;
    }

    void append(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
    }

    void prepend(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = newNode;
            head->next = head;
            head->prev = head;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void deleteNode(int data) {
        if (head) {
            Node* current = head;
            do {
                if (current->data == data) {
                    if (current == head) {
                        if (head->next == head) {
                            head = nullptr;
                        } else {
                            Node* tail = head->prev;
                            head = head->next;
                            tail->next = head;
                            head->prev = tail;
                        }
                    } else {
                        current->prev->next = current->next;
                        current->next->prev = current->prev;
                    }
                    delete current;
                    return;
                }
                current = current->next;
            } while (current != head);
        }
    }

    void deleteNodeByAddress(Node* node) {
        if (head && node) {
            if (node == head) {
                if (head->next == head) {
                    head = nullptr;
                } else {
                    Node* tail = head->prev;
                    head = head->next;
                    tail->next = head;
                    head->prev = tail;
                }
            } else {
                node->prev->next = node->next;
                node->next->prev = node->prev;
            }
            delete node;
        }
    }

    void display() {
        if (head) {
            Node* current = head;
            do {
                std::cout << current->data << " ";
                current = current->next;
            } while (current != head);
            std::cout << std::endl;
        }
    }
};
