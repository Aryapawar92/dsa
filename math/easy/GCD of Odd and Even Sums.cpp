/* 
You are given an integer n. Your task is to compute the GCD (greatest common divisor) of two values:

sumOdd: the sum of the smallest n positive odd numbers.

sumEven: the sum of the smallest n positive even numbers.

Return the GCD of sumOdd and sumEven.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int evenSum = 0 , oddSum = 0;
        for(int i =1;i<=2*n;i++){
            if(i%2 == 0) evenSum += i;
            else oddSum += i;
        }
        return gcd(evenSum,oddSum);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}