/* 
You are given a string s of length m consisting of digits. You are also given a 2D integer array queries, where queries[i] = [li, ri].

For each queries[i], extract the substring s[li..ri]. Then, perform the following:

Form a new integer x by concatenating all the non-zero digits from the substring in their original order. If there are no non-zero digits, x = 0.
Let sum be the sum of digits in x. The answer is x * sum.
Return an array of integers answer where answer[i] is the answer to the ith query.

Since the answers may be very large, return them modulo 109 + 7.

Input: s = "10203004", queries = [[0,7],[1,3],[4,6]]

Output: [12340, 4, 9]

Explanation:

s[0..7] = "10203004"
x = 1234
sum = 1 + 2 + 3 + 4 = 10
Therefore, answer is 1234 * 10 = 12340.
s[1..3] = "020"
x = 2
sum = 2
Therefore, the answer is 2 * 2 = 4.
s[4..6] = "300"
x = 3
sum = 3
Therefore, the answer is 3 * 3 = 9.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> BrutesumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        long long MOD = 1e9 + 7;
        int n = queries.size();
        for (int i = 0; i < n; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            int len = right - left + 1;
            long long sum = 0, num = 0;
            string sub = s.substr(left, len);
            for (auto it : sub) {
                int digit = it - '0';
                sum = (sum + digit) % MOD;
                if (digit != 0) {
                    num = (num * 10 + digit) % MOD;
                }
            }
            long long result = (num * sum) % MOD;
            ans.push_back(result);
        }
        return ans;
    }

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        long long MOD = 1e9+7;
        int n  = s.size();
        vector<long long> sumD(n + 1, 0), p(n + 1, 0);
        vector<int> cntN0(n + 1, 0);

        vector<long long> pow10(n + 1);
        pow10[0] = 1;
        for (int i = 1; i <= n; i++) pow10[i] = (pow10[i-1] * 10) % MOD;

        for (int i = 1; i <= n; i++) {
            int d = s[i-1] - '0';
            sumD[i] = (sumD[i-1] + d) % MOD;
            cntN0[i] = cntN0[i-1] + (d != 0 ? 1 : 0);
            p[i] = (d != 0) ? (p[i-1] * 10 + d) % MOD : p[i-1];
        }

        for (auto& q : queries) {
            int l = q[0], r = q[1];          
            int n0 = cntN0[r+1] - cntN0[l];
            long long sum = (sumD[r+1] - sumD[l] + MOD) % MOD;
            long long x = (p[r+1] - p[l] * pow10[n0] % MOD + MOD) % MOD;
            long long result = (x * sum) % MOD;
            ans.push_back((int)result);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}