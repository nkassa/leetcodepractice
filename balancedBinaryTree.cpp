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
    vector<int> leaf;
    bool isBalanced(TreeNode* root) 
    {
        dfs(root, 0);
        int mini = 100000;
        int maxi = 0;
        for(int num: leaf)
        {
            mini = min(mini, num);
            maxi = max(maxi, num);
        }
        cout << mini << " " << maxi << endl;
        long int ans = maxi - mini;
        return ans <= 1;
    }
    void dfs(TreeNode* root, int cnt)
    {
        if(root == nullptr)
        {
            return;
        }
        cnt++;
        if(!root->left && !root->right)
        {
            leaf.push_back(cnt);
        }
        dfs(root->left, cnt);
        dfs(root->right, cnt);
    }
};