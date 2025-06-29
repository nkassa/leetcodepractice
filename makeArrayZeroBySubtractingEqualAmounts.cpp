class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        priority_queue<int> maxHeap;
        for(int num: nums)
        {
            if(num != 0)
            {
                heap.push(num);
                maxHeap.push(num);
            }
        }
        int maxi = 0;
        if(!maxHeap.empty())
        {
            maxi = maxHeap.top();
        }
        int mini = 0;
        if(!heap.empty())
        {
            mini = heap.top();
        }
        if(mini != 0)
        {
            return maxi/mini;
        }
        return 0;
    }
};