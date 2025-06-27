class Solution {
public:
    vector<int> nums;
    Solution(vector<int>& nums) 
    {
        this->nums = nums;
    }
    
    vector<int> reset() 
    {
        return nums;
    }
    
    vector<int> shuffle() 
    {
        vector<int> res = nums;
        for(int i = res.size()-1; i > 0; i--)
        {
            int j = rand() % (i + 1);
            int temp = res[j];
            res[j] = res[i];
            res[i] = temp;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */