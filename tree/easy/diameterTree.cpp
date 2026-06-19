// Given the root of a binary tree, return the length of the diameter of the tree.

// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

// The length of a path between two nodes is represented by the number of edges between them.

#include <bits/stdc++.h>
using namespace std;

class Solution {

 struct TreeNode
{
   int val;
   TreeNode* left;
   TreeNode* right;

   TreeNode(int val): val(val),left(nullptr),right(nullptr) {}
};

public:
    int maxDiameter = 0;
    int calculateHeight(TreeNode* root) {
        if (root == nullptr) return 0;
        int leftHeight = calculateHeight(root->left);
        int rightHeight = calculateHeight(root->right);
        maxDiameter = max(maxDiameter, leftHeight + rightHeight);
        return 1 + max(leftHeight, rightHeight);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        maxDiameter = 0;
        calculateHeight(root);
        return maxDiameter;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}