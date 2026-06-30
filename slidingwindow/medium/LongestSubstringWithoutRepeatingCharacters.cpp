// Given a string s, find the length of the longest substring without duplicate characters.

// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
// "pwwkew"

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0; 
        int maxLen = 0;
        unordered_map<char, int> mpp;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (mpp[s[right]] > 0) {
                mpp[s[left]]--; 
                left++;         
            }
            mpp[s[right]]++;
        
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}