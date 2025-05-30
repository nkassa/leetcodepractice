class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        
        stack<int> stack;

        for(string s: tokens)
        {
            if(s != "+" && s != "-" && s != "*" && s != "/")
            {
                stack.push(stoi(s));
            }
            else if(s == "+" && stack.size() > 1)
            { 
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                stack.push(first+sec);
            }
            else if(s == "-" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                stack.push(sec-first);
            }
            else if(s == "*" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                stack.push(first*sec);
            }
            else if(s == "/" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                stack.push(sec/first);
            }
        }
        return stack.top();
    }
};