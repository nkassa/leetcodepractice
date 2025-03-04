class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        unordered_set<int> count;
        for(int num: nums)
        {
            if(count.find(num) != count.end())
            {
                return true;
            }
            count.insert(num);
        }
        return false;
    }
};