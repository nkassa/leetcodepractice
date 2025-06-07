class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
        }
        for(char c: t)
        {
            if(count.find(c) != count.end())
            {
                count[c]--;
                if(count[c] == 0)
                {
                    count.erase(c);
                }
            }
            else
            {
                count[c]++;
            }
        }
        return count.size() == 0;
    }
};