/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* ans;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        dfs(root, p->val, q->val, INT_MIN, INT_MAX);
        return ans;
    }
    void dfs(TreeNode* root, int p, int q, int min, int max)
    {
        if(root == nullptr)
        {
            return;
        }
        if((p > root->val && q < root->val) || (q > root->val && p < root->val) || root->val == p || root->val == q)
        {
            ans = root;
            return;
        }
        if(p < root->val && q < root->val)
        {
            dfs(root->left, p, q, min, root->val);
        }
        if(p > root->val && q > root->val)
        {
            dfs(root->right, p,q, root->val, max);
        }
    }
}; 