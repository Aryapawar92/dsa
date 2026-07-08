/* 


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        // very brute force solution , iterate the linkedlist and everytim check the value in the array
        // store the value in a map or a set as the constraint says those values are unique and then make the new list as the find operatrions thats o(1) but will take extra space   
        unordered_set<int> values(nums.begin(),nums.end());

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;

        while(curr->next != nullptr){
            if(values.count(curr->next->val)){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
            }
            else{
                curr = curr->next;
            }
        }
        ListNode* new_head = dummy->next;

        return new_head;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}