class Solution {
public:
    vector<string> commonChars(vector<string>& words) 
    {
        vector<int> minFreq(26, INT_MAX);
        for(string str: words)
        {
            vector<int> freq(26, 0);
            for(int i = 0; i < str.size(); i++)
            {
                freq[str[i]-'a']++;
            }
            for(int i = 0; i < 26; i++)
            {
                minFreq[i] = min(minFreq[i], freq[i]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < minFreq[i]; j++)
            {
                ans.push_back(string(1, 'a' + i));
            }
        }
        return ans;
    }
};