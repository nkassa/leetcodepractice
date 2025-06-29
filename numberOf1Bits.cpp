class Solution {
public:
    int hammingWeight(int n) 
    {
        long int ans = 0;
        while(n != 0)
        {
            ans += n % 2;
            n /= 2;
        }
        return ans;
    }
};

//__builtin_popcount