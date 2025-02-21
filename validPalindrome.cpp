class Solution {
public:
    bool isPalindrome(string s) 
    {
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(isalnum(s[left]) == false)
            {
                left++;
            }
            if(isalnum(s[right]) == false)
            {
                right--;
            }
            if(isalnum(s[left]) && isalnum(s[right]))
            {
                if(tolower(s[right]) == tolower(s[left]))
                {
                    left++;
                    right--;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};