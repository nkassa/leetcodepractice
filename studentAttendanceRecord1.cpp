class Solution {
public:
    bool checkRecord(string s) 
    {
        bool late = true;
        int cnt = 0;
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
            if(c == 'L')
            {
                cnt++;
            }
            else
            {
                cnt = 0;
            }
            if(cnt >= 3)
            {
                late = false;
            }
        }
        return count['A'] < 2 && late;
    }
};