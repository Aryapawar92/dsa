/* 
You are given the head of a linked list, which contains a series of integers separated by 0's. The beginning and end of the linked list will have Node.val == 0.

For every two consecutive 0's, merge all the nodes lying in between them into a single node whose value is the sum of all the merged nodes. The modified list should not contain any 0's.

Return the head of the modified linked list.

Input: head = [0,3,1,0,4,5,2,0]
Output: [4,11]
Explanation: 
The above figure represents the given linked list. The modified list contains
- The sum of the nodes marked in green: 3 + 1 = 4.
- The sum of the nodes marked in red: 4 + 5 + 2 = 11.


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
    ListNode* brutemergeNodes(ListNode* head) {
        vector<int> arr;
        int sum = 0;
        ListNode* temp = head;
        
        while (temp != nullptr) {
            if (temp->val == 0) {
                if (sum > 0) {
                    arr.push_back(sum);
                    sum = 0;
                }
            } else {
                sum += temp->val;
            }
            temp = temp->next;
        }
        if (arr.empty()) return nullptr;
        ListNode* newHead = new ListNode(arr[0]);
        ListNode* current = newHead;
        for (size_t i = 1; i < arr.size(); i++) {
            current->next = new ListNode(arr[i]);
            current = current->next;
        }
        return newHead;
    }

    ListNode* mergeNodes(ListNode* head) {
        ListNode* modify = head;
        ListNode* traverse = head->next;
        int sum = 0;

        while(traverse != nullptr){
            if(traverse->val == 0){
                modify->val = sum;
                sum = 0;
                if (traverse->next != nullptr) {
                    modify = modify->next;
                }
            }
            else{
                sum += traverse->val;
            }
            traverse = traverse->next;
        }
        modify->next = nullptr;
        return head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}