// Pre Order Traversal 
// Root -> left -> right
// it is uniquely suited for scenarios where the structure or hierarchy of the tree needs to be handled from top to bottom
// If you need to save a tree to a file (serialization) or create an exact copy of it in memory
// In an operating system, folders and files form a tree structure. To list directories hierarchically



#include <bits/stdc++.h>
using namespace std;

class Solution {
struct Node
{
   int data;
   Node* left;
   Node* right;

   Node(int val): data(val),left(nullptr),right(nullptr) {}
};


public:
    vector<int> ans;
    void preOrderRecursive(Node* root){
        if(root == nullptr) return;
        ans.push_back(root->data);
        preOrderRecursive(root->left);
        preOrderRecursive(root->right); 
    }

    void preOrderIterative(Node* root){
        if(root == nullptr) return;
        stack<Node*> st;
        st.push(root);

        while(!st.empty()){
            Node* current = st.top();
            ans.push_back(current->data);
            st.pop();

            if (current->right != nullptr) {
            st.push(current->right);
            }
            if (current->left != nullptr) {
                st.push(current->left);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}