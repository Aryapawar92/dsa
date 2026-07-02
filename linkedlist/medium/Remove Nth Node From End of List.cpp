class Solution {
    struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int length = 0;
        ListNode* curr = head;

        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }

        if (n == length) {
            return head->next;
        }

        curr = head;
        int steps = length - n - 1;

        while (steps--) {
            curr = curr->next;
        }

        curr->next = curr->next->next;

        return head;
    }
};