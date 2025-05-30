class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> list;
        for(string s: wordDict)
        {
            list.insert(s);
        }
        string word = "";
        for(char c: s)
        {
            word += c;
            if(list.find(word) != list.end())
            {
                return true;
            }
        }
        return false;
    }
};