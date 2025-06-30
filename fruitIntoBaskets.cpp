class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> count;
        for(int fruit: fruits)
        {
            count[fruit]++;
        }
        priority_queue<int, vector<int>, greater<int>> heap;
        for(auto [key, value]: count)
        {
            heap.push(value);
        }
        int ans = 0;
        int k = 0;
        while(k < 2 && !heap.empty())
        {
            k++;
            ans += heap.top();
            heap.pop();
        }
        return ans;
    }
};