#include"Binary_tree.hpp"

int main(){
    Node* root;
    root = binary_tree_construction(root);
    cout << endl << endl;
    level_order_traversal(root);
}