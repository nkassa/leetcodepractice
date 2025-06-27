class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> heap;
        for(int i = 0; i < points.size(); i++)
        {
            double diff = sqrt(points[i][0]*points[i][0] + points[i][1]*points[i][1]);
            heap.push({diff, i});
        }
        vector<vector<int>> ans;
        int cnt = 0;
        while(cnt < k)
        {
            ans.push_back(points[heap.top().second]);
            heap.pop();
            cnt++;
        }
        return ans;
    }
};