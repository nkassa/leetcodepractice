class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        int right = 0;
        int ans = -1;
        int size = haystack.size();
        while(right < size)
        {
            int idx = 0;
            int temp = right;
            while(haystack[right] == needle[idx] && right < size)
            {
                right++;
                idx++;
                if(idx == needle.size())
                {
                    return right - idx;
                }
            }
            if(haystack[right] != needle[idx])
            {
                right = temp + 1;;
            }
        }
        return ans;
    }
};