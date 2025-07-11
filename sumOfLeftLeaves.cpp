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
    int ans = 0;
    int sumOfLeftLeaves(TreeNode* root) 
    {
        dfs(root, false);
        return ans;
    }
    void dfs(TreeNode* root, bool leftSide)
    {
        if(!root)
        {
            return;
        }
        if(!root->left && !root->right && leftSide)
        {
            ans += root->val;
        }
        dfs(root->left, true);
        dfs(root->right, false);
    }
};