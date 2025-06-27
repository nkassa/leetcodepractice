class Solution {
public:
    vector<bool> seen;
    unordered_map<int,vector<int>> grid;
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        seen = vector(isConnected.size(), false);
        for(int i = 0; i < isConnected.size(); i++)
        {
            for(int j = 0; j < isConnected[i].size(); j++)
            {
                if(isConnected[i][j] == 1)
                {
                    grid[i].push_back(j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(seen[i] != true)
            {
                ans++;
                seen[i] = true;
                dfs(i);
            }
        }
        return ans;
    }
    void dfs(int i)
    {
        vector<int> neighbors = grid[i];
        for(int j = 0; j < neighbors.size(); j++)
        {
            if(seen[neighbors[j]] == false)
            {
                seen[neighbors[j]] = true;
                dfs(neighbors[j]);
            }
        }
    }
};//