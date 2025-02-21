class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(!isalnum(s[left]))
            {
                left++;
            }
            if(!isalnum(s[right]))
            {
                right--;
            }
            if(isalnum(s[left]) && isalnum(s[right]))
            {
                if(tolower(s[right]) != tolower(s[left]))
                {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};