class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        unordered_map<int,int> hashtable;
        for(int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if(hashtable.find(diff) != hashtable.end())
            {
                return {hashtable[diff], i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
};