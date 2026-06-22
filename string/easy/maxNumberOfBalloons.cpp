//Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

// You can use each character in text at most once. Return the maximum number of instances that can be formed.

// Input: text = "nlaebolko"
// Output: 1
// balloon

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> mpp;
        for(char c: text){
            mpp[c]++;
        } 
        int b = mpp['b'];
        int a = mpp['a'];
        int l = mpp['l'] / 2;
        int o = mpp['o'] / 2;
        int n = mpp['n'];
        return min({b, a, l, o, n});
    }
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}