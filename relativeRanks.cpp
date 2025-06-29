class Solution {
public:
    vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        vector<string> ans(score.size());
        priority_queue<pair<int,int>> heap;
        for(int i = 0; i < score.size(); i++)
        {
            heap.push({score[i], i});
        }
        int i = 0;
        while(!heap.empty())
        {
            int idx = heap.top().second;
            heap.pop();
            if(i < 3)
            {
                ans[idx] = medals[i];
            }
            else
            {
                ans[idx] = to_string(i+1);
            }
            i++;
        }
        return ans;
    }
};