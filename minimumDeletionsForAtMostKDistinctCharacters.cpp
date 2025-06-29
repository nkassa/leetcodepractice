class Solution {
public:
    int minDeletion(string s, int k) 
    {
        unordered_map<char,int> seen;
        for(char c: s)
        {
            seen[c]++;
        }
        priority_queue<pair<int,char>, vector<pair<int,char>>, greater<pair<int,char>>> heap;
        for(auto [key,val]: seen)
        {
            heap.push({val, key});
        }
        int ans = 0;
        while(seen.size() > k)
        {
            ans += heap.top().first;
            seen.erase(heap.top().second);
            heap.pop();
        }
        return ans;
    }
};