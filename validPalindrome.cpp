class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str = "";
        for(char c: s)
        {
            if(isalnum(c))
            {
                str += tolower(c);
            }
        }
        string strCopy = str;
        reverse(str.begin(), str.end());
        return strCopy == str;
    }
};
