// You are given three integers n, l, and r.

// A ZigZag array of length n is defined as follows:

// Each element lies in the range [l, r].
// No two adjacent elements are equal.
// No three consecutive elements form a strictly increasing or strictly decreasing sequence.
// Return the total number of valid ZigZag arrays.

// Since the answer may be large, return it modulo 109 + 7.

// A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).

// A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

// Input: n = 3, l = 4, r = 5

// Output: 2

// Explanation:

// There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

// [4, 5, 4]
// [5, 4, 5]​​​​​​​

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countZigzagArrays(int n, int l, int r) {
        long long m = r - l + 1;
        long long MOD = 1e9 + 7;
        if (n == 1) return m;
        vector<vector<long long>> dp(m + 1, vector<long long>(2, 0));

        for (int j = 1; j <= m; j++) {
            dp[j][0] = j - 1;     
            dp[j][1] = m - j;  
        }
        for (int i = 3; i <= n; i++) {
            vector<long long> pref_up(m + 1, 0);
            vector<long long> pref_down(m + 1, 0);
            
            for (int k = 1; k <= m; k++) {
                pref_up[k] = (pref_up[k - 1] + dp[k][0]) % MOD;
                pref_down[k] = (pref_down[k - 1] + dp[k][1]) % MOD;
            }
            vector<vector<long long>> next_dp(m + 1, vector<long long>(2, 0));

            for (int j = 1; j <= m; ++j) {
                next_dp[j][0] = pref_down[j - 1];
                long long total_up_sum = (pref_up[m] - pref_up[j] + MOD) % MOD;
                next_dp[j][1] = total_up_sum;
            }
            dp = move(next_dp);
        }
        long long total_distinct_arrays = 0;
        for (int j = 1; j <= m; j++) {
            total_distinct_arrays = (total_distinct_arrays + dp[j][0] + dp[j][1]) % MOD;
        }

        return total_distinct_arrays;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}