class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        unordered_set<char> seen;
        int left = 0;
        int ans = 0;
        for(int right = 0; right < s.size(); right++)
        {
            while(seen.find(s[right]) != seen.end())
            {
                seen.erase(s[left]);
                left++;
            }
            ans = max(ans, right-left+1);
            seen.insert(s[right]);
        }
        return ans;
    }
};