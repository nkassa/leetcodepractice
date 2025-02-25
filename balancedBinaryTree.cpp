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
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        dfs(root, 0);
        return ans;
    }
    int dfs(TreeNode* root, int cnt)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left, cnt++);
        int right = dfs(root->right, cnt++);
        if(!root->right && !root->left)
        {
            return cnt;
        }
        if(abs(right-left) > 1)
        {
            ans = false;
        }
        return 0;
    }
};

// been working for 2 days and can't figure it out
// try again tomorrow
