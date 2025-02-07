class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int left = 0;
        int right = height.size()-1;
        int ans = 0;
        int diff = right - left;
        while(left < right)
        {
            int x = min(height[right], height[left]);
            ans = max(ans, x * diff);
            if(height[left] > height[right])
            {
                right--;
            }
            else
            {
                left++;
            }
            diff--;
        }
        return ans;
    }
};