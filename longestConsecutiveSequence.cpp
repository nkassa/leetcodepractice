class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int ans = 0;
        unordered_set<int> seen;
        for(int num: nums)
        {
            seen.insert(num);
        }
        for(auto num: seen)
        {
            if(seen.find(num-1) != seen.end())
            {
                continue;
            }
            int size = 1;
            int val = num;
            while(seen.find(val+1) != seen.end())
            {
                val += 1;
                size++;
            }
            ans = max(ans, size);
        }
        return ans;
    }
};