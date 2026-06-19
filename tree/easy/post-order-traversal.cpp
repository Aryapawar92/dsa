// Post order Traversal
// Left -> right -> root

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
    void postOrderTraversal(Node* root){
        if(root == nullptr) return;
        postOrderTraversal(root->left);
        postOrderTraversal(root->right); 
        ans.push_back(root->data);
    }

    vector<int> postOrderIterativeTwoStack(Node* root){
        if(root == nullptr) return ans;
        stack<Node*> s1;
        stack<Node*> s2;

        while(!s1.empty()){
            Node* curr = s1.top();
            s1.pop();
            s2.push(curr);

            if (curr->left)  s1.push(curr->left);
            if (curr->right) s1.push(curr->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top()->data);
            s2.pop();
        }

        return ans;

    }

    vector<int> postOrderIterativeOneStack(Node* root){
        if(root == nullptr) return ans;

        stack<Node*> st;
        Node* curr = root;
        Node* prev = nullptr;
        while (curr != nullptr || !st.empty()) {
            if (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            } else {
                Node* peekNode = st.top();
                if (peekNode->right != nullptr && prev != peekNode->right) {
                    curr = peekNode->right;
                } else {
                    ans.push_back(peekNode->data);
                    prev = peekNode;
                    st.pop();
                }
            }
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}