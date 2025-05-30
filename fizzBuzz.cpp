class Solution {
public:
    vector<string> fizzBuzz(int n) 
    {
        vector<string> ans(n, "");
        for(int idx = 0; idx < n; idx++)
        {
            int num = idx+1;
            if(num % 3 == 0 && num % 5 == 0)
            {
                ans[idx] = "FizzBuzz";
            }
            else if(num % 3 == 0)
            {
                ans[idx] = "Fizz";
            }
            else if(num % 5 == 0)
            {
                ans[idx] = "Buzz";
            }
            else
            {
                ans[idx]= to_string(num);
            }
        }
        return ans;
    }
};