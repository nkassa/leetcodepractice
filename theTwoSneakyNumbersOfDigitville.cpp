class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) 
    {
        unordered_set<int> seen;
        vector<int> ans;
        for(int num: nums)
        {
            if(seen.find(num) != seen.end())
            {
                ans.push_back(num);
            }
            seen.insert(num);
        }
        return ans;
    }
};