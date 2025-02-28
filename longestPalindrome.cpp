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
        for(char c: s)
        {
            if(count.find(c) != count.end())
            {
                while(count[c] > 1)
                {
                    cnt += 2;
                    count[c] -= 2;
                }
                if(count[c] < 1)
                {
                    count.erase(c);
                }
            }
        }
        if(count.size() == 0)
        {
            return cnt;
        }
        return cnt+1;
    }
};