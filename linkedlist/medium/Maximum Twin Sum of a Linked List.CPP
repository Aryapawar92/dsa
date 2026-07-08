/* 
In a linked list of size n, where n is even, the ith node (0-indexed) of the linked list is known as the twin of the (n-1-i)th node, if 0 <= i <= (n / 2) - 1.

For example, if n = 4, then node 0 is the twin of node 3, and node 1 is the twin of node 2. These are the only nodes with twins for n = 4.
The twin sum is defined as the sum of a node and its twin.

Given the head of a linked list with even length, return the maximum twin sum of the linked list.

Input: head = [5,4,2,1]
Output: 6
Explanation:
Nodes 0 and 1 are the twins of nodes 3 and 2, respectively. All have twin sum = 6.
There are no other nodes with twins in the linked list.
Thus, the maximum twin sum of the linked list is 6. 

Input: head = [4,2,2,3]
Output: 7
Explanation:
The nodes with twins present in this linked list are:
- Node 0 is the twin of node 3 having a twin sum of 4 + 3 = 7.
- Node 1 is the twin of node 2 having a twin sum of 2 + 2 = 4.
Thus, the maximum twin sum of the linked list is max(7, 4) = 7. 

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
    int pairSum(ListNode* head) {
        // find the mid point
        // reverse the ll then find the max pair sum
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        while (curr) {
            ListNode* next_node = curr->next;
            curr->next = prev;
            prev = curr;                
            curr = next_node;
        }
        int max_sum = 0;
        ListNode* first_half = head;
        ListNode* second_half = prev;
        while (second_half) {
            max_sum = max(max_sum, first_half->val + second_half->val);
            first_half = first_half->next;
            second_half = second_half->next;
        }
        return max_sum;
    }    
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}