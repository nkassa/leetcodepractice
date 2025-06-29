/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(!root)
        {
            return {};
        }
        vector<vector<int>> ans = {};
        queue<TreeNode*> queue;
        queue.push(root);
        while(!queue.empty())
        {
            int size = queue.size();
            vector<int> curr = {};
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                curr.push_back(node->val);
                queue.pop();
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};