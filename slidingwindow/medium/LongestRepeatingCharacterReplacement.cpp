/**
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achieve this answer too.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int left = 0;
        int maxLen = 0;
        vector<int> count(26, 0);
        int maxRepeatCount = 0;
        for(int right=0;right<n;right++){
            int charIndex = s[right] - 'A';
            count[charIndex]++;
            int len = right-left+1;
            maxRepeatCount = max(maxRepeatCount, count[charIndex]);
            if(len-maxRepeatCount > k){
                int charIndex = s[left]-'A';
                count[charIndex]--;
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