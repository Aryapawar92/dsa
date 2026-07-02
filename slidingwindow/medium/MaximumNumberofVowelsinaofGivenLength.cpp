/* 

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.
Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.
Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int maxVowels(string s, int k) {
        int n = s.size();
        int current_vowels = 0;
        for (int i = 0; i < k; i++) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
        }

        int max_vowels = current_vowels;
        for (int i = k; i < n; i++) {
            if (isVowel(s[i])) {
                current_vowels++;
            }
            if (isVowel(s[i - k])) {
                current_vowels--;
            }
            max_vowels = max(max_vowels, current_vowels);
        }

        return max_vowels;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}