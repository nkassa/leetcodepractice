class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) 
    {
        string temp = "";
        unordered_map<string, int> count;
        for(int i = 0; i < paragraph.size(); i++)
        {
            if(isalpha(paragraph[i]))
            {
                paragraph[i] = tolower(paragraph[i]);
                temp += paragraph[i];
            }
            if((!isalpha(paragraph[i]) || i == paragraph.size()-1) && temp.size() != 0)
            {
                count[temp]++;
                temp = "";
            }
        }
        priority_queue<pair<int,string>> heap;
        for(auto [key,val]: count)
        {
            heap.push({val, key});
        }
        unordered_set<string> ban;
        for(string b: banned)
        {
            ban.insert(b);
        }
        while(!heap.empty() && ban.find(heap.top().second) != ban.end())
        {
            heap.pop();
        }
        return heap.top().second;
    }
};