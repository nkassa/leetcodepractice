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
    vector<int> nodes;
    bool isValidBST(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        dfs(root);
        for(int i = 1; i < nodes.size(); i++)
        {
            if(nodes[i-1] >= nodes[i])
            {
                return false;
            }
        }
        return true;
    }
    void dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return;
        }
        dfs(root->left);
        nodes.push_back(root->val);
        dfs(root->right);
    }
};