/* 
You are given two linked lists: list1 and list2 of sizes n and m respectively.

Remove list1's nodes from the ath node to the bth node, and put list2 in their place.

The blue edges and nodes in the following figure indicate the result:

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        // bring two pointer at a and b
        // then the next pointer on node a will point the head of list2 and the last node of list2 will point node b
        // return the head;
        ListNode* curr = list1;
        ListNode* prev = list1;
        ListNode* after = list1;
        for(int i =0;i<=b;i++){
            if(i == a-1){
                prev = curr;
            }
            curr = curr->next;
        }
        after = curr;
        prev->next = list2;
        ListNode* curr2 = list2;
        while (curr2->next != nullptr) {
            curr2 = curr2->next;
        }
        curr2->next = after;
        return list1;
    }    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}