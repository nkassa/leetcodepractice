class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char,int> count;
        for(auto letter: s)
        {
            count[letter]++;
        }

        for(auto letter: t)
        {
            if(count.find(letter) != count.end())
            {
                count[letter]--;
                if(count[letter] == 0)
                {
                    count.erase(letter);
                }
            }
            else
            {
                return false;
            }
        }
        return count.size() == 0;
    }
};