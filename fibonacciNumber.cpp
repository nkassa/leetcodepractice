class Solution {
public:
    vector<int> list;
    int fib(int n) 
    {
        if(n <= 1)
        {
            return n;
        }
        list = vector(n+1, -1);
        list[0] = 0;
        list[1] = 1;
        return dp(n);
    }
    int dp(int idx)
    {
        if(list[idx] != -1)
        {
            return list[idx];
        }
        list[idx] = dp(idx-1) + dp(idx-2);
        return list[idx];
    }
};