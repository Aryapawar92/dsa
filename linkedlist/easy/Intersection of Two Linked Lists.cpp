/* 
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,bool> mpp;
        ListNode* temp = headA;
        while(temp){
            mpp[temp] = true;
            temp = temp->next;
        }
        temp = headB;
        while(temp){
            if(mpp.find(temp) != mpp.end()) return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}