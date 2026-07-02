/* 
Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.

Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int left = 0;
        int sum = 0;
        int count = 0;
        int right = k;
        for(int i=0;i<k;i++){
            sum += arr[i];
        }
        while(right<n){
            int avg = sum/k;
            if(avg>= threshold) count++;
            sum -= arr[left++];
            sum += arr[right++];
        }
        if(sum / k >= threshold) {
        count++;
        }
        return count;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}