class Solution {
public:
    int longestPalindrome(string s) 
    {
        int cnt = 0;
        bool odd = false;
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
        }
        for(auto [key,val]: count)
        {
            if(val % 2 == 0)
            {
                cnt += val;
            }
            else
            {
                cnt += val - 1;
                odd = true;
            }
        }
        if(odd == true)
        {
            return cnt+1;
        }
        return cnt;
    }
};