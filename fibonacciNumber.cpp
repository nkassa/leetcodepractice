class Solution {
public:
    unordered_map<int,int> count = {{0,0}, {1,1}};
    int fib(int n) 
    {
        if(count.find(n) != count.end())
        {
            return count[n];
        }
        count[n] = fib(n-1) + fib(n-2);
        return count[n];
    }
};