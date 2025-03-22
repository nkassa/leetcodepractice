class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<vector<char>> letters = {{},{},{'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'}, {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
        vector<string> ans;
        string curr = {};
        backtrack(curr, ans, digits, letters, 0);
        return ans;
    }
};

void backtrack(string curr, vector<string>& ans, string& digits, vector<vector<char>>& letters, int x) 
{
    if (curr.size() == digits.size()) 
    {
        ans.push_back(curr);
        return;
    }

    for (int i = x; i < digits.size(); i++) 
    {
        for(int j = 0; j < letters[digits[i]].size(); j++)
        {
            curr += letters[digits[i]][j];
            backtrack(curr, ans, digits, letters, x += 1);
            curr.pop_back();
        }
        
    }
}