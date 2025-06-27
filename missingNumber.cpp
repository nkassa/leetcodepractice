class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        vector<bool> count(nums.size()+1, false);
        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]] = true;
        }
        for(int i = 0; i < count.size(); i++)
        {
            if(count[i] == false)
            {
                return i;
            }
        }
        return 0;
    }
};