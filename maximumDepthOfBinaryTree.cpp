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
    int maxDepth(TreeNode* root) 
    {
        if(root == nullptr)
        {
            return 0;
        }
        queue<TreeNode*> queue;
        queue.push(root);
        int cnt = 0;
        while(!queue.empty())
        {
            cnt++;
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* node = queue.front();
                queue.pop();
                if(node->left)
                {
                    queue.push(node->left);
                }
                if(node->right)
                {
                    queue.push(node->right);
                }
            }
        }
        return cnt;
    }
};