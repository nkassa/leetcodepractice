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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        int rem = 0;
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        while(l1 != nullptr && l2 != nullptr)
        {
            int val = l1->val + l2->val + rem;
            rem = val / 10;
            val %= 10;
            ListNode* curr = new ListNode(val);
            head->next = curr;
            head = head->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != nullptr)
        {
            int val = l1->val + rem;
            rem = val / 10;
            val %= 10;
            ListNode* curr = new ListNode(val);
            head->next = curr;
            head = head->next;
            l1 = l1->next;
        }
        while(l2 != nullptr)
        {
            int val = l2->val + rem;
            rem = val / 10;
            val %= 10;
            ListNode* curr = new ListNode(val);
            head->next = curr;
            head = head->next;
            l2 = l2->next;
        }
        if(rem != 0)
        {
            head->next = new ListNode(rem);
        }
        return ans->next;
    }
};