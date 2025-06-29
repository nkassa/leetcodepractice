class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int> heap;
        for(int gift: gifts)
        {
            heap.push(gift);
        }
        int i = 0;
        while(i < k && !heap.empty())
        {
            int val = heap.top();
            heap.pop();
            val = sqrt(val);
            heap.push(val);
            i++;
        }
        long long ans = 0;
        while(!heap.empty())
        {
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};