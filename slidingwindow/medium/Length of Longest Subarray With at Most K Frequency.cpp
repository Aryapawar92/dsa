/* 
You are given an integer array nums and an integer k.

The frequency of an element x is the number of times it occurs in an array.

An array is called good if the frequency of each element in this array is less than or equal to k.

Return the length of the longest good subarray of nums.

A subarray is a contiguous non-empty sequence of elements within an array.

Input: nums = [1,2,3,1,2,3,1,2], k = 2
Output: 6
Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
It can be shown that there are no good subarrays with length more than 6.

Input: nums = [1,2,1,2,1,2,1,2], k = 1
Output: 2
Explanation: The longest possible good subarray is [1,2] since the values 1 and 2 occur at most once in this subarray. Note that the subarray [2,1] is also good.
It can be shown that there are no good subarrays with length more than 2.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
           // keep left and right at 0
           // make a map of int,int and keep a track of the count
           // if the count exceeds k then keep moving the left till the count gets -1 
           // keep calculating the length of the window
           // [1,2,3,1,2,3,1,2]
           int n = nums.size();
           int left = 0;
           int maxLen = 0;
           unordered_map<int,int> mpp;
           for(int right = 0;right<n;right++){
                mpp[nums[right]]++;
                if(mpp[nums[right]] > k){
                    while(mpp[nums[right]] > k){
                        mpp[nums[left++]]--;
                    }
                }
                maxLen = max(maxLen,right-left+1);
           }
           return maxLen;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}