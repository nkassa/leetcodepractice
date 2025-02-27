class Solution {
public:
    int longestPalindrome(string s) 
    {
        int cnt = 0;
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
        }
        for(auto [key,val]: count)
        {
            while(val >= 2)
            {
                cnt += 2;
                val -= 2;
            }
        }
        return cnt+1;
    }
};