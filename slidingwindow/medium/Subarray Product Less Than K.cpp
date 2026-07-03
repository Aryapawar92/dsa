/* 

Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

[1, 2]

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // keep left and right at 0
        // keep a sum and keep on checking if it is below k or no
        // if yes then keep added right-left+1 to the total and return 
        // if not then reduce left--;
        int n = nums.size();
        int total =0;
        int left  = 0;
        int prodSum = 1;
        for(int right=0;right<n;right++){
            prodSum *= nums[right];
            while(prodSum >= k){
                prodSum /= nums[left++];
            }
            total += right-left+1;
        }   
        return total;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}