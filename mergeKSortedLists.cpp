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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(ListNode* curr: lists)
        {
            while(curr != nullptr)
            {
                heap.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode* final = new ListNode(0);
        ListNode* ans = final;
        while(!heap.empty())
        {
            ListNode* node = new ListNode(heap.top());
            heap.pop();
            final->next = node;        
            final = final->next;
        }
        return ans->next;
    }
};