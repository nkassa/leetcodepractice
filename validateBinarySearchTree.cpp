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
    void dfs(TreeNode* root, long int min, long int max)
    {
        if(root == nullptr)
        {
            return;
        }
        if(root->val <= min || root->val >= max)
        {
            ans = false;
            return;
        }
        dfs(root->left, min, root->val);
        dfs(root->right, root->val, max);
    }
};