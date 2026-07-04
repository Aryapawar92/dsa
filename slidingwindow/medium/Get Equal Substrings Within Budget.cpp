/* 
You are given two strings s and t of the same length and an integer maxCost.

You want to change s to t. Changing the ith character of s to ith character of t costs |s[i] - t[i]| (i.e., the absolute difference between the ASCII values of the characters).

Return the maximum length of a substring of s that can be changed to be the same as the corresponding substring of t with a cost less than or equal to maxCost. If there is no substring from s that can be changed to its corresponding substring from t, return 0.

Input: s = "abcd", t = "bcdf", maxCost = 3
Output: 3
Explanation: "abc" of s can change to "bcd".
That costs 3, so the maximum length is 3.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // keep left at 0 and right at 0 as well
        // keep moving right pointer and calculate the difference between the string
        // now add it to a temp variable and check if it is higher than maxCost or not 
        // if it is keep reducing the left pointer
        int n = s.size();
        if(n == 0) return 0;
        int maxLen = 0,left = 0 , tempCost = 0;
        for(int right=0;right<n;right++){
            int diff = abs(s[right]-t[right]);
            tempCost += diff;
            while(tempCost > maxCost){
                int diff = abs(s[left]-t[left]);
                tempCost -= diff;
                left++;
            }
            maxLen = max(maxLen,right-left+1);
        }
        return maxLen;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}