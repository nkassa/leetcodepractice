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
        ListNode* curr;
        ListNode* ans = new ListNode(0);
        ans->next = curr;
        while(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                curr = list1;
                list1 = list1->next;
            }
            else
            {
                curr = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        while(list1 != nullptr)
        {
            curr = list1;
            list1 = list1->next;
        }
        while(list2 != nullptr)
        {
            curr = list2;
            list2 = list2->next;
        }
        return ans->next;
    }
};