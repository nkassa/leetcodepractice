class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        unordered_map<string, vector<string>> count;
        string key;
        vector<vector<string>> ans;
        for(int i = 0; i < strs.size(); i++)
        {
            key = strs[i];
            sort(strs[i].begin(), strs[i].end());
            count[strs[i]].push_back(key);
        }
        for(auto [key,val]: count)
        {
            ans.push_back(val);
        }
        return ans;
    }
};