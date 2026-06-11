/*
Implement Upper Bound

Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the upper bound of x.

What is Upper Bound?
The upper bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than the given key i.e. x.

The upper bound is the smallest index, ind, where arr[ind] > x.
*/ 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int> nums,int x){
        int n = nums.size();
        int low = 0 , high = n-1;
        int index = -1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] > x){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return index;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}