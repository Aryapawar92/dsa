/* 
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.

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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // calculate the length of the linked list first
        // then modulo it with k 
        // youll get the number of linkedlist you can split that is for eg. if the length is 10 and k is 3 then 10%3 = 3 so the array size will be 3 but how will i find the size of the linkedlist in it;
        int len = 0;
        ListNode* temp = head;
        while(temp){
            len++;
            temp = temp->next;
        }
        int base_size = len/k;
        int remainder = len %k;
        vector<ListNode*> result(k, nullptr);
        temp = head;

        for (int i = 0; i < k; i++) {
            if (temp == nullptr) break; 
            result[i] = temp;
            int current_list_size = base_size + (i < remainder ? 1 : 0);
            for (int j = 0; j < current_list_size - 1; j++) {
                if (temp != nullptr) {
                    temp = temp->next;
                }
            }
            ListNode* next_part_head = temp->next;
            temp->next = nullptr;
            temp = next_part_head;
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    

    return 0;
}