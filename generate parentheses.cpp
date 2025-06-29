class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
        string curr = "";
        vector<string> ans;
        helper(n, curr, 0, 0, ans);
        return ans;
    }
    void helper(int& n, string curr, int open, int closed, vector<string>& ans)
    {
        if(curr.size() == 2*n)
        {
            ans.push_back(curr);
            return;
        }
        if(open < n)
        {
            helper(n, curr + '(', open +1, closed, ans);
        }
        if(open > closed)
        {
            helper(n, curr + ')', open, closed + 1, ans);
        }
    }
};