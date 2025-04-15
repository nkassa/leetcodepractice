class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int> ans;
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        priority_queue<pair<int,int>> heap;
        for(auto [key,val]: count)
        {
            heap.push({val, key});
        }
        for(int i = 0; i < k; i++)
        {
            int val = heap.top().second;
            ans.push_back(val);
            heap.pop();
        }
        return ans;
    }
};