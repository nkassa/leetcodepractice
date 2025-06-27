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
    unordered_map<Node*, Node*> seen;
    Node* cloneGraph(Node* node) 
    {
        if(node == nullptr)
        {
            return nullptr;
        }
        Node* currNode = new Node(node->val);
        seen[node] = currNode;
        for(auto neighbor: node->neighbors)
        {
            if(seen.find(neighbor) != seen.end())
            {
                seen[node]->neighbors.push_back(seen[neighbor]);
            }
            else
            {
                seen[node]->neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return seen[node];
    }
};