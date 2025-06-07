class Solution {
public:
    vector<char> list = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    
    string convertToTitle(int columnNumber) 
    {
        string ans = "";
        while(columnNumber > 0)
        {
            int num = (columnNumber-1) % 26;
            ans += list[num];
            columnNumber = (columnNumber - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};