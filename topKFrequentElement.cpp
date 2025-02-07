class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> count;
        priority_queue<pair<int,int>> heap;
        vector<int> ans;
        for(auto num: nums)
        {
            count[num]++;
        }
        for(auto [key,val]: count)
        {
            heap.push(pair(val,key));
        }
        for(int i = 0; i < k; i++)
        {
            ans.push_back(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};