// Given a string s consisting only of characters a, b and c.

// Return the number of substrings containing at least one occurrence of all these characters a, b and c.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int a = -1 , b = -1 , c = -1;
        for(int i=0;i<n;i++){
            if(s[i] == 'a') a = i;
            else if(s[i] == 'b') b = i;
            else c = i;
            int smallestVal = min(a,min(b,c));
            if(smallestVal >= 0) ans += smallestVal+1;
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}