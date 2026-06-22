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
    vector<vector<int>> ans;
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()){
            int size = q.size();
            vector<int> temp;
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                temp.push_back(node->val);
            }
            if(!leftToRight){
            reverse(temp.begin(), temp.end());
            }
        
            ans.push_back(temp);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}