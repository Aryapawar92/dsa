// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode(int val): val(val),left(nullptr),right(nullptr) {}
};

class Solution {
public:
    int maximumDepth(TreeNode* root){
        if(root == nullptr) return 0;

        int leftHeight = maximumDepth(root->left);
        int rightHeight = maximumDepth(root->right);

        return 1 + max(leftHeight,rightHeight);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}