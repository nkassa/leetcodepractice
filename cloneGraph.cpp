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
    unordered_map<Node*, Node*> count;
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        if(count.find(node) == count.end())
        {
            count[node] = new Node(node->val);
            for(Node* newNode: node->neighbors)
            {
                count[node]->neighbors.push_back(cloneGraph(newNode));
            }
        }
        return count[node];
    }
};