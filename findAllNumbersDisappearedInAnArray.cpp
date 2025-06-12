class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> list(n+1, 0);
        vector<int> ans;
        for(int num: nums)
        {
            list[num] = 1;
        }
        for(int i = 1; i < list.size(); i++)
        {
            if(list[i] == 0)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};