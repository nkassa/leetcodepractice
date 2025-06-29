class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        priority_queue<int> heap;
        for(int num: nums)
        {
            heap.push(num);
        }
        int ans = heap.top()-1;
        heap.pop();
        ans *= heap.top()-1;
        return ans;
    }
};