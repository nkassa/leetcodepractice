class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_set<char> count;
        unordered_set<char> list;
        for(int i = 0; i < p.size(); i++)
        {
            count.insert(p[i]);
        }
        int left = 0;
        vector<int> ans;
        for(int right = 0; right < s.size(); right++)
        {
            if(count.find(s[right]) != count.end())
            {
                list.insert(s[right]);
            }
            else if(count.find(s[right]) == count.end() || right-left > list.size())
            {
                left = right;
            }
            if(list.size() == p.size())
            {
                ans.push_back(left);
                left = right;
                list.clear();
            }
        }
        return ans;
    }
};