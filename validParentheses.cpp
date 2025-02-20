class Solution {
public:
    bool isValid(string s) 
    {
        unordered_map<char,char> count = {{')','('}, {']','['}, {'}','{'}};
        stack<char> stack;
        for(char c: s)
        {
            if(count.find(c) != count.end())
            {
                if(!stack.empty() && stack.top() == count[c])
                {
                    stack.pop();
                }
                else if(stack.empty() || stack.top() != count[c])
                {
                    return false;
                }
            }
            else
            {
                stack.push(c);
            }
        }
        return stack.size() == 0;
    }
};