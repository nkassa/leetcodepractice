class Solution {
public:
    bool isPalindrome(string s) 
    {
        string str = "";
        for(int i = 0; i < s.size(); i++)
        {
            if(isalnum(s[i]))
            {
                str += tolower(s[i]);
            }
        }
        cout << str << endl;
        int left = 0;
        int right = str.size()-1;
        while(left < right)
        {
            if(str[left] != str[right])
            {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};