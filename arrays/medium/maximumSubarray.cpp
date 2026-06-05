// kadane Algorithm

// Kadane's Algorithm : Maximum Subarray Sum in an Array


// Problem Statement: Given an integer array nums, find the subarray with the largest sum and return the sum of the elements present in that subarray.

// A subarray is a contiguous non-empty sequence of elements within an array.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Kadane Algorithm
    int maxSubArray(vector<int>& nums){
        int n = nums.size();
        int maxi = INT_MIN;
        int sum = 0;
        for(int i =0;i<n;i++){
            sum += nums[i];
            maxi = max(sum,maxi);
            if(sum < 0) sum =0;
        }
        return maxi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}