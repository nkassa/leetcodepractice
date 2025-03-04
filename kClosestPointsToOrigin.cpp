class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        vector<vector<int>> ans;
        priority_queue<vector<int>> heap;
        for(vector<int> point: points)
        {
            int dist = pow((point[0]-0),2)+ pow((point[1]-0), 2);
            heap.push({dist, point[0], point[1]});
            if(heap.size() > k)
            {
                heap.pop();
            }
        }
        while(!heap.empty())
        {
            ans.push_back({heap.top()[1], heap.top()[2]});
            heap.pop();
        }
        return ans;
    }
};