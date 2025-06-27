class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        unordered_set<int> count;
        for(int num: nums)
        {
            if(count.find(num) != count.end())
            {
                count.erase(num);
            }
            else
            {
                count.insert(num);
            }
        }
        for(auto key: count)
        {
            return key;
        }
        return 0;
    }
};