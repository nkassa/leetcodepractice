class Solution {
public:
    int climbStairs(int n) 
    {
        if(n <= 2)
        {
            return n;
        }
        int prev = 2;
        int prevTwo = 1;
        for(int i = 2; i < n; i++)
        {
            int temp = prev;
            prev = prev + prevTwo;
            prevTwo = temp;
        }
        return prev;
    }
};