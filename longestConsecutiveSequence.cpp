class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int start = 0;
        int end = 0;
        int ans= 0;
        unordered_set<int> seen(nums.begin(), nums.end());
        for(int num: nums)
        {
            if(seen.find(num-1) != seen.end())
            {
                continue;
            }
            start = num;
            while(seen.find(num+1) != seen.end())
            {
                end = num + 1;
                num++;
            }
            ans = max(ans, start-end);
        }
        return ans;
    }
};