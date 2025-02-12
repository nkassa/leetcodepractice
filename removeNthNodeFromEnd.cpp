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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Move fast n steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both slow and fast until fast reaches the end
        while(fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node
        slow->next = slow->next->next;

        return dummy->next; // Head might be deleted, so return dummy->next
    }
};