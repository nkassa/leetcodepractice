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
    void reorderList(ListNode* head) 
    {
        if(head == nullptr)
        {
            return;
        }

        stack<ListNode*> stack;
        ListNode* curr = head;
        while(curr != nullptr)
        {
            stack.push(curr);
            curr = curr->next;
        }

        int size = stack.size();
        int cnt = 1;

        ListNode* ans = head;
        ListNode* c = ans;
        curr = head->next;

        while(cnt < size)
        {
            if(cnt % 2 == 0)
            {
                ans->next = curr;
                curr = curr->next;
            }
            else
            {
                ans->next = stack.top();
                stack.pop();
            }
            ans = ans->next;
            cnt++;
        }
        ans->next = nullptr;
        head = c;
    }
};