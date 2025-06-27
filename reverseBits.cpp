class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        bitset<32> b(n);
        string s = b.to_string();
        reverse(s.begin(), s.end());
        
        uint32_t ans = 0;
        for(char c: s)
        {
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }
};