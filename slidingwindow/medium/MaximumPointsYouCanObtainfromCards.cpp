/**
 
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

[1,79,80,1,1,1,200,1] k =3
[100,40,17,9,73,75] k = 3
[11,49,100,20,86,29,72] k =4
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0 , rsum = 0 ,maxSum = 0;
        int n = cardPoints.size();

        for(int i =0;i<k;i++){
            lsum += cardPoints[i];
            maxSum = lsum;
        }
        int rindex = n-1;
        for(int i = k -1;i>=0;i--){
            lsum = lsum - cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;
            maxSum = max(maxSum,rsum+lsum);
        }

        return maxSum;
        
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}