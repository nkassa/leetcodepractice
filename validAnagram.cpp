class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> count;
        unordered_map<char,int> count_two;
        for(char c: s)
        {
            count[c]++;
        }
        for(char c: t)
        {
            count_two[c]++;
        }
        for(auto [key,val]: count)
        {
            count_two[key] -= val;
            if(count_two[key] == 0)
            {
                count_two.erase(key);
            }
        }
        return count_two.size() == 0;
    }
};