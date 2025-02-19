

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> count;
        for(int i = 0; i < nums.size();i++)
        {
            int diff = target - nums[i];
            if(count.find(diff) != count.end())
            {
                return {i, count[diff]};
            }
            count[nums[i]] = i;
        }
        return {};
    }
};