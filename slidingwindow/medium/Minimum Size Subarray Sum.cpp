/* 

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // keep a left and right pointer at 0
        // keep a currSum and minLen variable
        // if the currSum gets >= use the min function to get the smallest length
        // now if the currSum gets higher than the target keep reducing the left++;
        int n = nums.size();
        int left = 0 , minLen = n+1 , currSum = 0;
        for(int right =0;right<n;right++){
            currSum += nums[right];
            while(currSum >= target){
                minLen = min(minLen,right-left+1);
                currSum -= nums[left++];
            }
        }
        return (minLen == n + 1) ? 0 : minLen;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}