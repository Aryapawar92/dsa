//Program to generate Pascal's Triangle

// Problem Statement: Write a program to generate Pascal's triangle. In Pascal’s triangle, each number is the sum of the two numbers directly above it as shown in the figure below:

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i =0;i<numRows;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}