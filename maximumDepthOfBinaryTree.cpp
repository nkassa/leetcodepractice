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
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }
        dfs(root, 1);
        return ans;
    }
    void dfs(TreeNode* root, int depth)
    {
        if(root == nullptr)
        {
            return;
        }
        ans = max(ans, depth);
        depth++;
        dfs(root->left, depth);
        dfs(root->right, depth);
    }
};