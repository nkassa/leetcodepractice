class Solution {
public:
    unordered_map<int, string> count;
    string longestPalindrome(string s) 
    {
        for(int i = 0; i < s.size(); i++)
        {
            pali(s, i, i+1);
            pali(s, i, i);
        }
        int maxi = 0;
        for(auto [key,val]: count)
        {
            maxi = max(maxi, key);
        }
        return count[maxi];
    }
    void pali(string& s, int left, int right)
    {
        int cnt = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left--;
            right++;
        }
        cnt = right - left -1;
        count[cnt] = s.substr(left+1, cnt);
    }
};