class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        if(tokens.size() == 0)
        {
            return 0;
        }
        int ans = stoi(tokens[0]);
        stack<int> stack;
        for(string s: tokens)
        {
            if(s != "+" && s != "-" && s != "*" && s != "/")
            {
                cout << stoi(s) << endl;
                stack.push(stoi(s));
            }
            else if(s == "+" && stack.size() > 1)
            { 
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                ans = first + sec;
                stack.push(ans);
            }
            else if(s == "-" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                ans = sec - first;
                stack.push(ans);
            }
            else if(s == "*" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                cout << first << " " << sec << endl;
                ans = first * sec;
                stack.push(ans);
            }
            else if(s == "/" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                cout << first << " " << sec << endl;
                ans = sec / first;
                stack.push(ans);
                cout << "stack " << stack.top() << endl;
            }
            cout << "ans " << ans << endl;
        }
        return ans;
    }
};