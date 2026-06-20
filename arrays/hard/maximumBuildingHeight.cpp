/**
 * 
 * You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.

    However, there are city restrictions on the heights of the new buildings:

    The height of each building must be a non-negative integer.
    The height of the first building must be 0.
    The height difference between any two adjacent buildings cannot exceed 1.
    Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.

    It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.

    Return the maximum possible height of the tallest building.
 */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        restrictions.push_back({n, n - 1});
        sort(restrictions.begin(), restrictions.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        int m = restrictions.size();

        for(int i = 1;i<m;i++){
            int prev_id = restrictions[i - 1][0];
            int prev_h = restrictions[i - 1][1];
            int curr_id = restrictions[i][0];
            int curr_h = restrictions[i][1];

            restrictions[i][1] = min(curr_h, prev_h + (curr_id - prev_id));
        }

        for (int i = m - 2; i >= 0; --i) {
            int curr_id = restrictions[i][0];
            int curr_h = restrictions[i][1];
            int next_id = restrictions[i + 1][0];
            int next_h = restrictions[i + 1][1];
            
            restrictions[i][1] = min(curr_h, next_h + (next_id - curr_id));
        }

        int max_overall_height = 0;
        for (int i = 0; i < m - 1; ++i) {
            int id1 = restrictions[i][0];
            int h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0];
            int h2 = restrictions[i + 1][1];
            
            int peak = (h1 + h2 + (id2 - id1)) / 2;
            max_overall_height = max(max_overall_height, peak);
        }
        
        return max_overall_height;

    }
};