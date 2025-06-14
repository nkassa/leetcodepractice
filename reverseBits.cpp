class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        string s = bitset<32>(n).to_string();
        reverse(s.begin(), s.end());
        
        uint32_t ans = 0;
        for(char c: s)
        {
            ans = ans * 2 + (c - '0');
        }
        return ans;
    }
};