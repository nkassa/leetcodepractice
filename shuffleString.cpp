class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        unordered_map<int,char> count;
        for(int i = 0; i < s.size(); i++)
        {
            count[indices[i]] = s[i];
        }
        string ans = "";
        for(int i = 0; i < indices.size(); i++)
        {
            ans += count[i];
        }
        return ans;
    }
};