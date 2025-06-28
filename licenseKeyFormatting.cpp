class Solution {
public:
    string licenseKeyFormatting(string s, int k) 
    {
        string ans = "";
        int size = s.size()-1;
        int cnt = 0;
        while(size >= 0)
        {
            if(isalnum(s[size]))
            {
                if(cnt == k)
                {
                    ans += '-';
                    cnt = 0;
                }
                ans += toupper(s[size]);
                cnt++;
            }
            size--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};