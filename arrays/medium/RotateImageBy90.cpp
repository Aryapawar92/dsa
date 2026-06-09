// Problem Statement: Given an N * N 2D integer matrix, rotate the matrix by 90 degrees clockwise. The rotation must be done in place, meaning the input 2D matrix must be modified directly..

// Input :matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
// matrix = [[7, 4, 1], [8, 5, 2], [9, 6, 3]]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void BruteRotateImage(vector<vector<int>>& matrix){

    }

    void optimalRotateImage(vector<vector<int>>& matrix){
        int n = matrix.size();

        for(int i =0;i<n;i++){
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }

        for(int i =0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}