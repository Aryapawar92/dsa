/* 

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of s2.

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        unordered_map<char,int> s1Mpp;
        unordered_map<char,int> s2Mpp;

        for (int i = 0; i < n1; i++) {
            s1Mpp[s1[i]]++;
            s2Mpp[s2[i]]++;
        }
        if (s1Mpp == s2Mpp) return true;

        for (int right = n1; right < n2; right++) {
            s2Mpp[s2[right]]++;
            s2Mpp[s2[right-n1]]--;
            if (s2Mpp[s2[right-n1]] == 0) {
                s2Mpp.erase(s2[right-n1]);
            }
            if (s1Mpp == s2Mpp) return true;
        }
    
        return false;
    }
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}