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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        dfs(root, subRoot);
        return ans;
    }

    void dfs(TreeNode* root, TreeNode* subRoot)
    {
        if(root == nullptr && subRoot == nullptr)
        {
            return;
        } 
        if(root == nullptr)
        {
            ans = false;
            return;
        }
        if(subRoot == nullptr)
        {
            return;
        }
        if(root->val == subRoot->val)
        {
            dfs(root->left, subRoot->left);
            dfs(root->right, subRoot->right);
        }
        else
        {
            dfs(root->left, subRoot);
            dfs(root->right, subRoot);
        }
    }
};