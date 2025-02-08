class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> count;
        unordered_map<char,int> count_two;
        for(auto letter: t)
        {
            count[letter]++;
        }
        for(auto letter: s)
        {
            count_two[letter]++;
        }

        return count == count_two;
    }
};