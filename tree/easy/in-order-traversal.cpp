// In order Traversal
// Left -> root -> right

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
    void inOrderTraversal(Node* root){
        if(root == nullptr) return;
        inOrderTraversal(root->left);
        ans.push_back(root->data);
        inOrderTraversal(root->right);
    }

    void inOrderIterative(Node* root){
        stack<Node*> st;
        Node* curr = root;
        while(curr != nullptr || !st.empty()){
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}