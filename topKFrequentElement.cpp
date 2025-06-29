class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        priority_queue<pair<int,int>> heap;
        for(auto [key, val]: count)
        {
            heap.push({val, key});
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