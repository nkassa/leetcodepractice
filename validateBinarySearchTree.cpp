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
    bool ans = true;
    bool isValidBST(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        dfs(root, LONG_MIN, LONG_MAX);
        return ans;
    }
    void dfs(TreeNode* root, long int mini, long int maxi)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->val <= mini || root->val >= maxi)
        {
            ans = false;
            return;
        }
        dfs(root->left, mini, root->val);
        dfs(root->right, root->val, maxi);
    }
};