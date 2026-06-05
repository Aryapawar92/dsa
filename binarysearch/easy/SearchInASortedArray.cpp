// Search in a Sorted Array

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int> nums,int val){
        int n = nums.size();
        int low = 0 , high = n-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(nums[mid] == val) return mid;
            else if(nums[mid] > val) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}