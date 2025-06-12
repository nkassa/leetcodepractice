class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        stringstream ss(s);
        string temp = "";
        int ans;
        while(getline(ss, temp, ' '))
        {
            if(temp.size() > 0)
            {
                ans = temp.size();
            }
        }
        return ans;
    }
};//