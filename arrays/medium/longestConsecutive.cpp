// Longest Consecutive Sequence in an Array

// Example 1:
// Input:
//  nums = [100, 4, 200, 1, 3, 2]  
// Output:
//  4  
// Explanation:
//  The longest sequence of consecutive elements in the array is [1, 2, 3, 4], which has a length of 4. This sequence can be formed regardless of the initial order of the elements in the array.

// [1,2,6,7,8]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Sorting takes nlogn 
    int longestConsecutive(vector<int> nums){
        int n = nums.size();
        if(n == 0) return 0;
        int maxLen = 1;
        int currLen = 1;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n-1;i++){
            if(nums[i]+1 == nums[i+1]){
                currLen++;
                maxLen = max(maxLen,currLen);
            }else if(nums[i] == nums[i+1]){
                continue;
            }
            else{
                currLen = 1;
            }
        }
        maxLen = max(maxLen,currLen);
        return maxLen;
    }
    int OptimalLongestConsecutive(vector<int> nums){
        int n = nums.size();
        if(n == 0) return 0;
        set<int> st(nums.begin(),nums.end());
        int maxLen = 0;
        for(auto it: st){
            if(st.find(it-1) == st.end()){
                int currNum = it;
                int currLen = 1;
                while(st.find(currNum+1) != st.end()){
                    currLen++;
                    currNum++;
                }
                maxLen = max(maxLen,currLen);
            }
        }
        return maxLen;
    }
        
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}