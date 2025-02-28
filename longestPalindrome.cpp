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
            while(val > 1)
            {
                cnt += 2;
                val -= 2;
            }
            if(val == 0)
            {
                count.erase(key);
            }
        }
        if(count.size() == 0)
        {
            return cnt;
        }
        return cnt+1;
    }
};