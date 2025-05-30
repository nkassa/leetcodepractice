class Solution {
public:
    int fib(int n) 
    {
        if(n == 1 || n == 0)
        {
            return n;
        }
        vector<int> list(n+1, -1);
        return dp(n, list);
    }
    int dp(int n, vector<int>& list)
    {
        if(n == 0 || n == 1)
        {
            return n;
        }
        if(list[n] >= 0)
        {
            return list[n];
        }
        list[n] = dp(n-1, list) + dp(n-2, list);
        return list[n];
    }
};