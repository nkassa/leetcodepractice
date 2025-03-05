class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        int ans = 0;
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
                ans += first + sec;
                cout << "ans " << ans << endl;
            }
            else if(s == "-" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                ans += first - sec;
            }
            else if(s == "*" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                ans += first * sec;
                cout << "ans " << ans << endl;
            }
            else if(s == "/" && stack.size() > 1)
            {
                int first = stack.top();
                stack.pop();
                int sec = stack.top();
                stack.pop();
                ans += first / sec;
            }
            stack.push(ans);
        }
        return ans;
    }
};