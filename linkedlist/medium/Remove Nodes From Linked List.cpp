/* 
You are given the head of a linked list.

Remove every node which has a node with a greater value anywhere to the right side of it.

Return the head of the modified linked list.



*/

class Solution {
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };

public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        head = reverseList(head);
        ListNode* curr = head;
        int maxSeen = head->val;

        while (curr->next != nullptr) {
            if (curr->next->val < maxSeen) {
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
                maxSeen = curr->val;
            }
        }

        return reverseList(head);
    }
};