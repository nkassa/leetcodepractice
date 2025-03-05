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
        unordered_map<Node*, Node*> count;
        if(node == nullptr)
        {
            return nullptr;
        }
        if(node->neighbors.size() == 0)
        {
            Node* clone = new Node(node->val);
            return clone;
        }
        return dfs(node, count);
    }
    Node* dfs(Node* node, unordered_map<Node*,Node*> count)
    {
        vector<Node*> neighbor;
        Node* clone = new Node(node->val);
        count[node] = clone;
        for(Node* newNode: node->neighbors)
        {
            if(count[newNode] != count.end())
            {
                neighbor.push_back(count[newNode]);
            }
            else
            {
                neighbor.push_back(dfs(newNode, count));
            }
        }
        clone->neighbors = neighbour;
        return clone;
    }
};