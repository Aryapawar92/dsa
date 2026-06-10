// Majority Elements(&gt;N/3 times) | Find the elements that appears more than N/3 times in the array


// Problem Statement: Given an integer array nums of size n. Return all elements which appear more than n/3 times in the array. The output can be returned in any order.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> MajorityElement(vector<int> nums){
        int n = nums.size();
        int candidate1 = 0;
        int candidate2 = 0;
        int sum1 = 0;
        int sum2 = 0;
        vector<int> ans;
        for(int num : nums){
           if(num == candidate1) sum1++;
           else if(num == candidate2) sum2++;
           else if(sum1 == 0) {
                candidate1 = num;
                sum1 = 1;
           }
           else if(sum2 == 0){
                candidate2 = num;
                sum2 = 1;
           }
           else{
                sum1--;
                sum2--;
           }
        }
        int actualCount1 = 0;
        int actualCount2 = 0;
        for(int num: nums){
            if(num == candidate1) actualCount1++;
            if(num == candidate2) actualCount2++;
        }
        if(actualCount1 > n/3) ans.push_back(candidate1);
        if(actualCount2 > n/3) ans.push_back(candidate2);

        return ans;

    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}