// Problem Statement: Given an array Arr[] of integers, rearrange the numbers of the given array into the lexicographically next greater permutation of numbers.

// If such an arrangement is not possible, it must rearrange to the lowest possible order (i.e., sorted in ascending order).

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> nums){
        int n = nums.size();
        int breakingPoint = -1;
        for(int i =n-1;i>0;i--){
            if(nums[i] > nums[i-1]) {
                breakingPoint = i-1;
                break;
            }
        }
        if(breakingPoint == -1) {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i =n-1;i>breakingPoint;i--){
            if(nums[i] > nums[breakingPoint]) {
                swap(nums[i],nums[breakingPoint]);
                break;
            }
        }
        reverse(nums.begin() + breakingPoint + 1, nums.end());
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}