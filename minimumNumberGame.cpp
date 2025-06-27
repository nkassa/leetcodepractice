class Solution {
public:
    vector<int> numberGame(vector<int>& nums) 
    {
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int num: nums)
        {
            heap.push(num);
        }
        vector<int> ans;
        while(!heap.empty())
        {
            int alice = heap.top();
            heap.pop();
            int bob = heap.top();
            heap.pop();
            ans.push_back(bob);
            ans.push_back(alice);
        }
        return ans;
    }
};