#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
#define fs(i, k) for(int i{0}; i<k; i++)
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    Node(){
        this->data = 0;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* binary_tree_construction(Node* root){
    cout << "Enter data for root node: ";
    int data;
    cin >> data;
    if (data == -1) return NULL;
    root = new Node(data);
    cout << "Enter the data for inserting in left of " << data << endl;
    root->left = binary_tree_construction(root->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    root->right = binary_tree_construction(root->right);
    return root;
}

void level_order_traversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if (temp == NULL){
            cout << endl;
            if (!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout << temp->data<< " ";
            if (temp->left){
                q.push(temp->left);
            }
            if (temp->right){
                q.push(temp->right);
            }
        }
    }
}