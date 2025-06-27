class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) 
    {
        int ans = 0;
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        vector<int> twice;
        for(auto [key,val]: count)
        {
            if(val == 2)
            {
                twice.push_back(key);
            }
        }
        if(twice.size() > 0)
        {
            ans = twice[0];
        }
        for(int i = 1; i < twice.size(); i++)
        {
            ans ^= twice[i];
        }
        return ans;
    }
};