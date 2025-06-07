class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> ans;
        unordered_map<int,int> count;
        for(int num: nums1)
        {
            count[num]++;
        }
        for(int num:nums2)
        {
            if(count.find(num) != count.end())
            {
                ans.push_back(num);
                count[num]--;
                if(count[num] == 0)
                {
                    count.erase(num);
                }
            }
        }
        return ans;
    }
};