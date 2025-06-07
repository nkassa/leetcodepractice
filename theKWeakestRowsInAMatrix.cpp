class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int row = 0; row < mat.size(); row++)
        {
            int cnt = 0;
            for(int col = 0; col < mat[0].size(); col++)
            {
                if(mat[row][col] == 1)
                {
                    cnt++;
                }
            }
            heap.push({cnt, row});
        }
        vector<int> ans;
        for(int i = 0; i < k; i++)
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};