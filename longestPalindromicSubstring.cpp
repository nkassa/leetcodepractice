class Solution {
public:
    string longestPalindrome(string s) 
    {
        if(s.size() == 0 || s.size() == 1)
            return s;

        else 
        {
            string pal = "";
            int low = 0;
            int high = 0;
            string sub = "";
            for(int i = 0; i < s.size()-1; i++)
            {
                low = i;
                high = i + 1;
                while(low >= 0 && high < s.size())
                {
                    if(low == i && s[low] == s[high])
                    {
                        high += 1;
                        continue;
                    }
                    if(low > 0 && s[low-1] == s[high])
                    {
                        low -= 1;
                        high += 1;
                    }
                    else 
                    {
                        break;
                    }
                }
                sub = s.substr(low, high-low);
                if ( pal.length() < sub.length())
                {
                    pal = sub;
                }
            }  
            return pal; 
        }
    }
};