/* 
Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.

The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.

Return the number of remaining intervals.

Example 1:

Input: intervals = [[1,4],[3,6],[2,8]]
Output: 2
Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
Example 2:

Input: intervals = [[1,4],[2,3]]
Output: 1


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // c <= a and b <= d.
        sort(intervals.begin(), intervals.end(), [](const vector<int>& i1, const vector<int>& i2) {
            if (i1[0] == i2[0]) {
                return i1[1] > i2[1];
            }
            return i1[0] < i2[0];
        });

        int remainingCount = 0;
        int maxEnd = 0;

        for (const auto& curr : intervals) {
            if (curr[1] > maxEnd) {
                remainingCount++;
                maxEnd = curr[1];
            }
        }

        return remainingCount;
    }
};