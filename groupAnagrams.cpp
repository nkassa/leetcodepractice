class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> count;
        for(string str: strs)
        {
            string s = str;
            sort(str.begin(), str.end());
            count[str].push_back(s);
        }
        for(auto [key,val]: count)
        {
            ans.push_back(val);
        }
        return ans;
    }
};