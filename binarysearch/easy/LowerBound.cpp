/***
 * 
 * Implement Lower Bound

Problem Statement: Given a sorted array of N integers and an integer x, write a program to find the lower bound of x.

What is lower bound?
The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.

The lower bound is the smallest index, ind, where arr[ind] >= x. But if any such index is not found, the lower bound algorithm returns n i.e. size of the given array.

Example 1:
Input Format: N = 4, arr[] = {1,2,2,3}, x = 2
Result: 1
Explanation: Index 1 is the smallest index such that arr[1] >= x.
 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lowerBound(vector<int> nums,int x){
        int n = nums.size();
        int index = 0;
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(nums[mid] >= x){
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