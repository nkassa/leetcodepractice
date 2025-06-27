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
    bool isSymmetric(TreeNode* root) 
    {
        return dfs(root->left, root->right);
    }
    bool dfs(TreeNode* leftSide, TreeNode* rightSide)
    {
        if(!leftSide && !rightSide)
        {
            return true;
        }
        else if(!leftSide || !rightSide || rightSide->val != leftSide->val)
        {
            return false;
        }
        return dfs(leftSide->right, rightSide->left) && dfs(leftSide->left, rightSide->right);
    }
};