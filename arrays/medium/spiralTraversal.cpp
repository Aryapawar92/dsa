// Problem Statement: Given a Matrix, print the given matrix in spiral order.
// Input: Matrix[][] = { { 1, 2, 3, 4 },{ 5, 6, 7, 8 },{ 9, 10, 11, 12 },{ 13, 14, 15, 16 } }
// Outhput: 1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.
// Explanation: The output of matrix in spiral form.

/**
 * [
 *  1,2,3
 *  4,5,6
 *  7,8,9
 * ]
 * output: [1,2,3,6,9,8,7,4,5]
 * keep i = 0 , j = n-1 , basically
 * 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralTraversal(vector<vector<int>> matrix){
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = m-1;
        while(top <= bottom && left <= right){
            for(int i =left;i<=right;i++){
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                ans.push_back(matrix[i][right]);
            }
            right--;
            if(top <= bottom) {
                for(int i = right; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            if(left <= right) {
                for(int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
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