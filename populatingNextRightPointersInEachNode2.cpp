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
        queue<Node*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            Node* prev = nullptr;
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                Node* node = queue.front();
                queue.pop();
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
                if(prev)
                {
                    prev->next = node;
                }
                prev = node;
            }
        }
        return root;
    }
};