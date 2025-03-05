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
        Node* clone = new Node(node->val);
        count[node] = clone;

        while(!queue.empty())
        {

            Node* node = queue.front();
            queue.pop();

            for(Node* newNode: node->neighbors)
            {
                if(count.find(newNode) == count.end())
                {
                    count[newNode] = new Node(newNode->val);
                    queue.push(newNode);
                }
                count[node]->neighbors.push_back(count[newNode]);
            }
        }
        return clone;
    }
};