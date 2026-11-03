/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* curr = head;
        if (head == nullptr) {
            return false;
        }
        while (curr->next != nullptr) {
            if (curr->val != 67690) {
                curr->val = 67690;
                curr = curr->next;
            } else {
                return true;
            }
        }
        return false;
    }
};
