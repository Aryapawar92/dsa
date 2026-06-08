// Set Matrices Zero

// Problem Statement: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix..



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void bruteSetZeros(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j] == 0){
                    for(int col =0;col<n;col++){
                        if(matrix[i][col] != 0) matrix[i][col] = -1;
                    }
                    for(int row=0;row<m;row++){
                        if(matrix[row][j] != 0) matrix[row][j] = -1;
                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == -1)
                    matrix[i][j] = 0;
            }
        }
    }

    void betterSetZeros(vector<vector<int>>& matrix){
        int n = matrix.size(); // row
        int m = matrix[0].size(); // col

        vector<int> col(m,0);
        vector<int> row(n,0);
        
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(matrix[i][j] == 0){
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(row[i] == 1 || col[j] == 1) matrix[i][j] = 0;
            }
        }
    }

    void optimalSetZeros(vector<vector<int>>& matrix){
        int n = matrix.size();
        int m = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        for(int i =0;i<n;i++){
            if(matrix[i][0] == 0){
                firstRowZero = true;
                break;
            }
        }

        for(int i =0;i<m;i++){
            if(matrix[0][i] == 0){
                firstColZero = true;
                break;
            }
        }

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}