class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int longest = 0;
        int ans = 0;
        unordered_set<int> seen(nums.begin(), nums.end());

        for(int num: seen)
        {
            if(seen.find(num-1) != seen.end())
            {
                continue;
            }
            longest = 1;
            while(seen.find(num+longest) != seen.end())
            {
                longest++;
            }
            ans = max(ans, longest);
            longest = 0;
        }
        return ans;
    }
};