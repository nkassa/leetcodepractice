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
        if(!head)
        {
            return nullptr;
        }
        Node* curr = head;
        while(curr)
        {
            Node* copy = new Node(curr->val);
            copy->next = curr->next;
            curr->next = copy;
            curr = copy->next;
        }
        curr = head;
        while(curr)
        {
            if(curr->random)
            {
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        Node* ans = head->next;
        curr = head;
        Node* copyCurr = ans;
        while(curr)
        {
            curr->next = curr->next->next;
            if(copyCurr->next)
            {
                copyCurr->next = copyCurr->next->next;
            }
            curr = curr->next;
            copyCurr = copyCurr->next;
        }
        return ans;
    }
};

// step 1
/*

orgininal list = 1->2->3

change list to = 1->1'->2->2'->3->3'

steps:
curr = head
while curr:
copy = new node with orig val
copy->next = curr->next
curr->next = copy
curr = copy->next

*/

// step 2
/*

copy over the random access

steps:
curr = head
while curr:
if curr->random
  curr->next->random = curr->random->next
curr = curr->next->next
*/

// step 3
/*

separate the orig and copy

steps:
ans = head->next
curr = head
copyCurr = ans
while curr:
curr->next = curr->next->next
if copyCUrr->next:
copyCurr->next = copyCurr->next->next

curr = curr->next
copyCurr = copyCurr->next

*/

/*
Map Method:
class Solution {
public:
    Node* copyRandomList(Node* head) 
    {
        unordered_map<Node*, Node*> list;
        list[nullptr] = nullptr;
        Node* curr = head;
        while(curr)
        {
            list[curr] = new Node(curr->val);
            curr = curr->next;
        }
        curr = head;
        while(curr)
        {
            list[curr]->next = list[curr->next];
            list[curr]->random = list[curr->random];
            curr = curr->next;
        }
        return list[head];
    }
};
*/