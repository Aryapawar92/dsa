/* 
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.


Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:

Input: nums = [5,6,7,8,9], x = 4
Output: -1
Example 3:

Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        // keep left at 0 and right at n-1
        // run a while loop between left and right
        // now take the greatest value either from left and right
        // check if x gets less than zero
        // if it does then take the other smaller value else continue
        // eventually calculate the ops else return -1
        int totalSum = 0;
        for (int num : nums) totalSum += num;
        int target = totalSum - x;
        if (target == 0) return nums.size();
        int n = nums.size();
        int left = 0, currSum = 0, maxLen = -1;
        for (int right = 0; right < n; right++) {
            currSum += nums[right];
            while (currSum > target && left <= right) {
                currSum -= nums[left];
                left++;
            }
            if (currSum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }
        return (maxLen == -1) ? -1 : (n - maxLen);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}