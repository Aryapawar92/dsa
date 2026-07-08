/* 
Given the head of a linked list, rotate the list to the right by k places.

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // very brute force solution is calculate the len then move the new pointer till n%k then play with the pointers
        if (!head || !head->next || k == 0) return head;
        int len =1;
        ListNode* curr = head;
        while(curr->next){
            curr = curr->next;
            len++;
        }
        k = k%len;
        if(k == 0) return head;
        curr->next = head;
        int steps = len-k;
        ListNode* new_tail = head;
        for(int i =1;i<steps;i++){
            new_tail = new_tail->next;
        }

        ListNode* new_head = new_tail->next;
        new_tail->next = nullptr;
        
        return new_head;
        
    }
    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}