class Solution {
public:
    int countPrimes(int n) 
    {
        vector<bool> list(n+1, true);
        for(int p = 2; p * p <= n; p++)
        {
            if(list[p])
            {
                for(int i = p * p; i <= n; i++)
                {
                    list[i] = false;
                }
            }
        }
        int ans = 0;
        for(int i = 2; i < list.size(); i++)
        {
            if(list[i])
            {
                ans++;
            }
        }
        return ans;
    }
};