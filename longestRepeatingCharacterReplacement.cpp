class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        int ans = 0;
        int cnt = 0;
        string letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int i = 0; i < letters.size(); i++)
        {
            int left = 0;
            for(int right = 0; right < s.size(); right++)
            {
                if(letters[i] != s[right])
                {
                    cnt++;
                }
                while(cnt > k)
                {
                    if(letters[i] != s[left])
                    {
                        cnt--;
                    }
                    left++;
                }
                ans = max(ans, right-left+1);
            }
            cnt = 0;
        }
        return ans;
    }
};