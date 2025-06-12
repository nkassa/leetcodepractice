class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> seen;
        for(string word: wordDict)
        {
            seen.insert(word);
        }
        int left = 0;
        string temp = "";
        for(int right = 0; right < s.size(); right++)
        {
            temp += s[right];
            if(seen.find(temp) != seen.end())
            {
                left = right + 1;
                temp = "";
            }
        }
        return left >= s.size();
    }
};