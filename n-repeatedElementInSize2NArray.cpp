class Solution {
public:
    int repeatedNTimes(vector<int>& nums) 
    {
        int n = nums.size() / 2;
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        for(auto [key, val]: count)
        {
            if(val == n)
            {
                return key;
            }
        }
        return 0;
    }
};