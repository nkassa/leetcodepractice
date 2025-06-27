class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        unordered_map<int,vector<vector<int>>> count;
        for(vector<int> time: times)
        {
            count[time[0]].push_back({time[1], time[2]});
        }

        vector<bool> seen(n+1, false);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, k});
        int visited = 0;
        int ans = 0;
        while(!heap.empty())
        {
            int cost = heap.top()[0];
            int node = heap.top()[1];
            heap.pop();
            if(seen[node] == true)
            {
                continue;
            }
            seen[node] = true;
            visited++;
            ans = max(ans, cost);
            for(vector<int> dest: count[node])
            {
                if(seen[dest[0]] == false)
                {
                    heap.push({cost + dest[1], dest[0]});
                }
            }
        }
        if(visited == n)
        {
            return ans;
        }
        return -1;
    }
};
//