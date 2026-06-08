// Check if one string is rotation of another


// Problem Statement: Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.
// A shift on s consists of moving the leftmost character of s to the rightmost position. For example, if s = "abcde", then it will be "bcdea" after one shift.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkStrings(string s,string goal){
      return s.size() == goal.size() && (s+s).find(goal) != -1;  
    };
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}