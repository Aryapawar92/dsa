// Given a binary array nums and an integer k, return the maximum number of consecutive 1's in the array if you can flip at most k 0's.

// Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
// Output: 6
// Explanation: [1,1,1,0,0,1,1,1,1,1,1]
// Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int left = 0;
        int countZeros = 0;
        for(int right = 0;right<n;right++){
            if(nums[right] == 0){
                countZeros++;
            }
            while(countZeros > k){
                if(nums[left] == 0) countZeros--;
                left++;
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