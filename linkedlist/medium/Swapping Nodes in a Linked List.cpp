/* 
You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp = head;

        for(int i = 1;i<k;i++){
            temp = temp->next;
        }
        ListNode* curr = temp;
        ListNode* second = head;

        while(temp != NULL && temp->next != NULL){
            second = second->next;
            temp = temp->next;
        }

        int temp1 = second->val;
        second->val = curr->val;
        curr->val = temp1;

        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}