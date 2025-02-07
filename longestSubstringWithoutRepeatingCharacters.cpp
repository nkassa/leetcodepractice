class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_map<char,int> count;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++)
        {
            count[s[right]] += 1;
            while(count[s[right]] > 1)
            {
                count[s[left]]--;
                left++;
            }
            ans = max(ans, right-left+1);
        }
        return ans;
    }
};