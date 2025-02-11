class Solution {
public:
    bool isPalindrome(string s) 
    {
        string word= "";
        for(char c: s)
        {
            if(isalpha(c) || isdigit(c))
            {
                word += c;
            }
        }
        int left = 0;
        int right = word.size()-1;
        while(left < right)
        {
            if( tolower(word[left]) != tolower(word[right]))
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};