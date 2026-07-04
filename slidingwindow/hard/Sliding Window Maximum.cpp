/* 
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // keep left at zero and move right till k and keep the maxElement in a variable and secondMax Element
        // then run the loop from right till n
        // now if you find an element that is greater than the element replace the max with that and replace the second max with the oldest
        // along with that keep a track that the left one is not one of those element
        // asked ai for this because i didnt know the concept of deque here
        // so instead of using two variable , what i can do is use deque that store the indices of the elements
        // maintain the queue as monotonically decreasing
        // the index of the largest element in the current window will always be at the front of the deque.
        int n = nums.size();
        vector<int> result;
        deque<int> dq;
        for(int right = 0;right<n;right++){
            if(!dq.empty() && dq.front() < right -k +1){
                dq.pop_front();
            }
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}