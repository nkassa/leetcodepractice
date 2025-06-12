class Solution {
public:
    int countSegments(string s) 
    {
        int ans = 0;
        string temp = "";
        stringstream ss(s);
        while(getline(ss, temp, ' '))
        {
            if(temp.size() > 0)
            {
                ans++;
            }
        }
        return ans;
    }
};