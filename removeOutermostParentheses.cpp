class Solution {
public:
    string removeOuterParentheses(string s) 
    {
        vector<string> list;
        int cnt = 1;
        string str = s[0];
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == '(')
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
            str += s[i];
            if(cnt == 0)
            {
                list.push_back(str);
            }
        }
        string ans = "";
        for(int i = 0; i < list.size(); i++)
        {
            string curr = list[i];
            curr.pop_back();
            curr.erase(curr.begin());
            ans += curr;
        }
        return ans;
    }
};