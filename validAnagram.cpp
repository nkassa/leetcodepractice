class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> count;
        unordered_map<char,int> count2;
        for(char c: s)
        {
            count[c]++;
        }
        for(char c: t)
        {
            count2[c]++;
        }
        for(auto [key, val]: count)
        {
            if(val != count2[key])
            {
                return false;
            }
            
        }
        for(auto [key, val]: count2)
        {
            if(val != count[key])
            {
                return false;
            }
            
        }
        return true;
    }
};