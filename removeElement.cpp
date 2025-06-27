class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        int i = 0;
        for(auto [key,value]: count)
        {
            while(key != val && value > 0)
            {
                nums[i] = key;
                i++;
                value--;
            }
        }
        return i;
    }
};