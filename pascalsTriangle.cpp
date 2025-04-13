class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans(numRows);
        if(numRows == 1)
        {
            ans[0] = {1};
            return ans;
        }
        else if(numRows == 2)
        {
            ans[0] = {1};
            ans[1] = {1,1};
            return ans;
        }
        ans[0] = {1};
        ans[1] = {1,1};
        for(int i = 2; i < numRows; i++)
        {
            vector<int> curr = {1};
            for(int j = 0; j < i-1; j++)
            {
                curr.push_back(ans[i-1][j]+ans[i-1][j+1]);
            }
            curr.push_back(1);
            ans[i] = curr;
        }
        return ans;
    }
};