class Solution {
public:
    string s;
    string t;
    bool isSubsequence(string s, string t) 
    {
        this->s = s;
        this->t = t;
        return dp(0, 0);
    }
    bool dp(int i, int j)
    {
        if(i == s.size())
        {
            return true;
        }
        if(j == t.size())
        {
            return false;
        }
        if(s[i] == t[j])
        {
            return dp(i+1, j+1);
        }
        else
        {
            return dp(i, j+1);
        }
    }
};