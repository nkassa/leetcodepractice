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
    int diff = 0;
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        dfs(root);
        return diff <= 1;
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        diff = max(diff, abs(right-left));
        return max(left,right) +1;
    }
};

//finally worked

/*

class Solution {
public:
    int diff = 0;
    bool isBalanced(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return true;
        }
        dfs(root);
        return diff <= 1;
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr)  
        {
            return 0;                  // for node 20 we have left = 0 right = 0 return 1
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        cout << left << " " << root->val << " " << right  << " " << max(left,right) +1 << endl;
        diff = max(diff, abs(right-left));
        return max(left,right) +1;
    }
};
*/