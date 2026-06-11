// Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

// Example 1:
// Input:
//  nums = [-1,0,1,2,-1,-4]
// Output:
//  [[-1,-1,2],[-1,0,1]]
// Explanation:
//  Out of all possible unique triplets possible, [-1,-1,2] and [-1,0,1] satisfy the condition of summing up to zero with i!=j!=k

#include <bits/stdc++.h>
using namespace std;

// Brute force is running 3 loops i , j , k putting them in set and then eventually returning the an 2d array
// do the sum but with 2 loops i , j .....
// optimal -> sort the array then keep a pointer at the start and at the end and one in the middle
// 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> nums){
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum > 0){
                    k--;

                }
                else{
                    j++;
                }
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