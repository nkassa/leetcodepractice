/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) 
    {
        if(!root)
        {
            return nullptr;
        }
        Node* leftMost = root;
        while(leftMost)
        {
            Node* currLevel = leftMost;
            leftMost = nullptr;
            Node* prev = nullptr;
            while(currLevel)
            {
                if(currLevel->left)
                {
                    if(prev)
                    {
                        prev->next = currLevel->left;
                    }
                    else
                    {
                        leftMost = currLevel->left;
                    }
                    prev = currLevel->left;
                }
                if(currLevel->right)
                {
                    if(prev)
                    {
                        prev->next = currLevel->right;
                    }
                    else
                    {
                        leftMost = currLevel->right;
                    }
                    prev = currLevel->right;
                }
                currLevel = currLevel->next;
            }
        }
        return root;
    }
};



