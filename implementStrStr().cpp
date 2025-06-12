class Solution {
public:
    int strStr(string haystack, string needle) 
    {
        long int i = 0;
        long int j = 0;
        while(i < haystack.size() && j < needle.size())
        {
            long int start = i;
            while(haystack[i] == needle[j] && i < haystack.size() && j < needle.size())
            {
                i++;
                j++;
            }
            if(j == needle.size())
            {
                return start;
            }
            if(haystack[i] != needle[j])
            {
                i = start+1;
                j = 0;
            }
        }
        return -1;
    }
};