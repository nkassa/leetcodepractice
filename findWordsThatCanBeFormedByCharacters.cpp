class Solution {
public:
    int countCharacters(vector<string>& words, string chars) 
    {
        int ans = 0;
        unordered_map<char, int> count;
        for(int i = 0; i < chars.size(); i++)
        {
            count[chars[i]]++;
        }
        for(string word: words)
        {
            bool cant = false;
            unordered_map<char, int> curr = count;
            for(int i = 0; i < word.size(); i++)
            {
                if(curr[word[i]] > 0)
                {
                    curr[word[i]]--;
                }
                else
                {
                    cant = true;
                    break;
                }
            }
            if(cant == false)
            {
                ans += word.size();
            }
        }
        return ans;
    }
};