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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        if(list1 == nullptr)
        {
            return list2;
        }
        if(list2 == nullptr)
        {
            return list1;
        }
        if(list1 == nullptr && list2 == nullptr)
        {
            return nullptr;
        }
        ListNode* ans  = new ListNode(0);
        dummy = ans;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val <= list2->val)
            {
                dummy->next = list1;
            }
        }
    }
};