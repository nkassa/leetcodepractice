class Solution {
public:
    int fib(int n) 
    {
        if(n == 1 || n == 0)
        {
            return n;
        }
        vector<int> list(n+1, -1);
        list[0] = 0;
        list[1] = 1;
        return dp(n, list);
    }
    int dp(int n, vector<int>& list)
    {
        if(list[n] >= 0)
        {
            return list[n];
        }
        list[n] = dp(n-1, list) + dp(n-2, list);
        return list[n];
    }
};