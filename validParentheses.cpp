class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,char> count = {{'[', ']'}, {'{', '}'}, {'(', ')'}};
        stack<char> stack;
        for(int i = 0; i < s.size(); i++)
        {
            if(count.find(s[i]) == count.end())
            {
                if(stack.empty() || count[stack.top()] != s[i])
                {
                    return false;
                }
                else
                {
                    stack.pop();
                }
            }
            else
            {
                stack.push(s[i]);
            }
        }
        return stack.size() == 0;
    }
};