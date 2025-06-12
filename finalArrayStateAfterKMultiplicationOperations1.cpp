class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) 
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;
        for(int i = 0; i < nums.size(); i++)
        {
            heap.push({nums[i], i});
        }
        for(int i = 0; i < k; i++)
        {
            int val = heap.top().first;
            int idx = heap.top().second;
            heap.pop();
            val *= multiplier;
            heap.push({val, idx});
        }
        while(!heap.empty())
        {
            int val = heap.top().first;
            int idx = heap.top().second;
            nums[idx] = val;
            heap.pop();
        }
        return nums;
    }
};