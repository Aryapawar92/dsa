/* 

You are given an integer array nums and a positive integer k.

Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.

A subarray is a contiguous sequence of elements within an array.

Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        // leetcode 2962
        // iterate the array first and then get the max Number
        // then run a loop till you atleast k occurences of the maxNumber
        // start counting the subarrays 
        // but im getting confused as to how to calculate the count of the subarrays  
        int n = nums.size();
        int maxNumber = nums[0];
        for(auto it: nums){
            maxNumber = max(it,maxNumber);
        } 
        long long count = 0;
        int maxElementCount = 0;
        int left = 0;
        for(int right = 0;right<n;right++){
            if (nums[right] == maxNumber) {
                maxElementCount++;
            }
            while(maxElementCount == k){
                if (nums[left] == maxNumber) {
                    maxElementCount--;
                }
                left++;
            }
            count += left;
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}