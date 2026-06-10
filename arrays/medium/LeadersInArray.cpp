//Example 1:
// Input:
//  arr = [4, 7, 1, 0]  
// Output:
//  7 1 0  
// Explanation:
//  The rightmost element (0) is always a leader.  
// 7 and 1 are greater than the elements to their right, making them leaders as well.

//Input:
//  arr = [10, 22, 12, 3, 0, 6]  
// Output:
//  22 12 6  

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leaders(vector<int> nums){
        int n = nums.size();
        int maxElement = INT_MIN;
        vector<int> ans;
        for(int i =n-1;i>=0;i--){
            if(nums[i] > maxElement){
                ans.push_back(nums[i]);
                maxElement = nums[i];
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}