class Solution {
public:
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    string reverseVowels(string s) 
    {
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            if(vowel.find(s[left]) != vowel.end() && vowel.find(s[right]) != vowel.end())
            {
                char temp = s[left];
                s[left] = s[right];
                s[right] = temp;
                left++;
                right--;
            }
            else if(vowel.find(s[left]) != vowel.end())
            {
                right--;
            }
            else if(vowel.find(s[right]) != vowel.end())
            {
                left++;
            }
            else
            {
                left++;
                right--;
            }
        }
        return s;
    }
};