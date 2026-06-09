// Problem Statement: Given an array of integers and an integer k, return the total number of subarrays whose sum equals k. A subarray is a contiguous non-empty sequence of elements within an array.

// Input : N = 4, array[] = {3, 1, 2, 4}, k = 6
// Output: 2
// Explanation: The subarrays that sum up to 6 are [3, 1, 2] and [2, 4].

// keep two pointers i and j at 0 keep adding the sum till it either equals to k if it equals to k then counter++ if it exceeds reduce i if not keep moving j

// Input: nums = [1,1,1], k = 2
// Output: 2

// Input: nums = [1,2,3], k = 3
// Output: 2


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int contiguosSum(vector<int> nums,int k){
        int n = nums.size();
        int currSum = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(auto it: nums){
            currSum += it;
            int remove = currSum - k;
            if(mpp.find(remove) != mpp.end()){
                count += mpp[remove];
            }
            mpp[currSum]++;
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}