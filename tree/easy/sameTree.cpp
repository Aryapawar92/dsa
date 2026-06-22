#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr || p->val != q->val) return false;
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);   
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}