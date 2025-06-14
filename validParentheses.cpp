class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,char> count = {{'}', '{'}, {']', '['}, {')', '('}};
        stack<char> stack;
        for(char c: s)
        {
            if(count.find(c) == count.end())
            {
                stack.push(c);
            }
            else
            {
                if(stack.empty() || stack.top() != count[c])
                {
                    return false;
                }
                stack.pop();
            }
        }
        return stack.size() == 0;
    }
};