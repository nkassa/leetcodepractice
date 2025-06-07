class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        unordered_map<int,int> count;
        for(int num: nums)
        {
            count[num]++;
        }
        int idx = 0;
        for(int i = 0; i < 3; i++)
        {
            int size = count[i];
            while(size > 0)
            {
                nums[idx] = i;
                idx++;
                size--;
            }
        }
    }
};