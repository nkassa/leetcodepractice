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
    bool isValidBST(TreeNode* root) 
    {
        vector<int> list;
        if(root == nullptr)
        {
            return true;
        }
        dfs(root, list);
        for(int i = 1; i < list.size(); i++)
        {
            if(list[i-1] > list[i])
            {
                return false;
            }
        }
        return true;
    }
    void dfs(TreeNode* root, vector<int>& list)
    {
        if(root == nullptr)
        {
            return;
        }
        dfs(root->left, list);
        list.push_back(root->val);
        dfs(root->right, list);
    }
};
//work