class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> count;
        for(int i = 0; i < nums.size(); i++)
        {
            if(count.find(target - nums[i]) != count.end())
            {
                return {i, count[target - nums[i]]};
            }
            count[nums[i]] = i;
        }
        return {};
    }
};

//hi