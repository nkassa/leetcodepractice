/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        Node* curr = new Node(0);
        curr->random = nullptr;
        curr->next = nullptr;
        Node* ans = curr;
        while(head != nullptr)
        {
            curr->next = new Node(head->val);
            curr->next->random = head->random;
            curr = curr->next;
            head = head->next;
        }
        return ans->next;
    }
};