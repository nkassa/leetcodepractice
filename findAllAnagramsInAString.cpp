class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        unordered_set<char> count;
        for(int i = 0; i < p.size(); i++)
        {
            count.insert(p[i]);
        }
        int left = 0;
        vector<int> ans;
        for(int right = 0; right < s.size(); right++)
        {
            if(right - left == p.size())
            {
                ans.push_back(left);
            }
            if()
        }
    }
};