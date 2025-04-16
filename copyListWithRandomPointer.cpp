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
        Node* ans = new Node(0);
        Node* curr = ans;
        curr->next = nullptr;
        curr = curr->next;
        while(head != nullptr)
        {
            curr = new Node(head->val);
            curr->random = head->random;
            curr->next = nullptr;
            head = head->next;
            curr = curr->next;
        }
        return ans->next;
    }
};