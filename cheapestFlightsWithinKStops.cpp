class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<vector<int>> costs(n, vector<int>(k+2,INT_MAX));
        unordered_map<int, vector<pair<int,int>>> distance;
        for(vector<int> flight: flights)
        {
            distance[flight[0]].push_back({flight[1], flight[2]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> heap;
        heap.push({0, src, 0});
        costs[src][0] = 0;
        while(!heap.empty())
        {
            vector<int> front = heap.top();
            heap.pop();
            int cost = front[0];
            int node = front[1];
            int stops = front[2];
            if(node == dst)
            {
                return cost;
            }
            for(auto neighbor: distance[node])
            {
                if(stops + 1 <= k + 1 && costs[neighbor.first][stops+1] > cost+neighbor.second)
                {
                    heap.push({cost+neighbor.second, neighbor.first, stops + 1});
                    costs[neighbor.first][stops+1] = cost+neighbor.second;
                }
            }
        }
        return -1;
    }
};