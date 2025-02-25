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
        int left = dfs(root->left, 0);
        int right = dfs(root->right, 0);
        int ans = abs(right-left);
        return ans <= 1;
    }
    int dfs(TreeNode* root, int cnt)
    {
        if(!root->left && !root->right)
        {
            cout << cnt << " " << root->val << endl;
            return cnt;
        }
        int left = dfs(root->left, cnt += 1);
        int right = dfs(root->right, cnt += 1);
        cout << left << " " << root->val << " " << right << endl;
        return 0;
    }
};