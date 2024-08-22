#include <iostream> 
#include "Linked_List.hpp"
using namespace std;

int main () {

    Node* root = new Node();
    for (int i{19}; i<24; i++) {
        root->insert_at_head(root, i);
    }
    root->print(root);
}