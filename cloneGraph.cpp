/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) 
    {
        unordered_map<Node*,Node*> count;
        if(node == nullptr)
        {
            return nullptr;
        }
        queue<Node*> queue;
        queue.push(node);
        while(!queue.empty())
        {
            vector<Node*> list;
            Node* node = queue.front();
            queue.pop();
            Node* clone = new Node(node->val);
            count[node] = clone;
            for(Node* newNode: node->neighbors)
            {
                if(count.find(newNode) != count.end())
                {
                    list.push(count[newNode]);
                }
                else
                {
                    queue.push(newNode);
                }
            }
            clone->neighbors = list;
        }
        return clone;
    }
};