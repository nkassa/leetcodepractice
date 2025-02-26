class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> count;
        for(char c: ransomNote)
        {
            count[c]++;
        }
        for(char c: magazine)
        {
            if(count.find(c) != count.end())
            {
                count[c]--;
                if(count[c] == 0)
                {
                    count.erase(c);
                }
            }
        }
        return count.size() == 0;
    }
};