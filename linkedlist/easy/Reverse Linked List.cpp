/* 
Reverse a Linked List


1->2->3->4->5
5->4->3->2->1

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

public:
    ListNode* reverseList(ListNode* head) {
        // one curr one prev and one next pointer
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while(curr){
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }

    ListNode* reverseLinkedList(ListNode* head){
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;

        return newHead;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}