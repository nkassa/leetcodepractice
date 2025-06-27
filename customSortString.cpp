class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> count;
        for(int i = 0; i < s.size(); i++)
        {
            count[s[i]] += 1;
        }
        string ans;
        for(int i = 0; i < order.size(); i++)
        {
            while(count[order[i]] > 0)
            { 
                ans += order[i];
                count[order[i]] -= 1; 
            }
        }
        for(int i = 0; i < s.size(); i++)
        {
            while(count[s[i]] > 0)
            {
                ans += s[i];
                count[s[i]] -= 1; 
            }
        }
        return ans;
    }
};