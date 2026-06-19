// Level Order Traversal (BFS)

// Finding the Shortest Path: In an unweighted tree or graph, BFS guarantees that the first time you reach a node, you've found the shortest path to it.

// Serialization/Deserialization: Many databases and frameworks save trees level-by-level because it's incredibly easy to reconstruct the tree from this linear format.

// Network Broadcasting: Sending a packet to all neighboring nodes, then to their neighbors, mirrors how data spreads across a network.

#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> ans;
    vector<int> levelOrderTraversal(TreeNode* root){
        if(root == nullptr) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            ans.push_back(curr->data);
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
            q.push(curr->right);
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