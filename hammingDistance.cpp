class Solution {
public:
    int hammingDistance(int x, int y) 
    {
        string x_string = "";
        string y_string = "";
        while(x != 0)
        {
            x_string += to_string(x % 2);
            x /= 2;
        }
        while(y != 0)
        {
            y_string += to_string(y % 2);
            y /= 2;
        }
        
        int idx_x = 0;
        int idx_y = 0;
        int ans = 0;
        while(idx_x < x_string.size() && idx_y < y_string.size())
        {
            if(x_string[idx_x] != y_string[idx_y])
            {
                ans++;
            }
            idx_x++;
            idx_y++;
        }
        while(idx_x < x_string.size())
        {
            if(x_string[idx_x] == '1')
            {
                ans++;
            }
            idx_x++;
        }
        while(idx_y < y_string.size())
        {
            if(y_string[idx_y] == '1')
            {
                ans++;
            }
            idx_y++;
        }
        return ans;
    }
};