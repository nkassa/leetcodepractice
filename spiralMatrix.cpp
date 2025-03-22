class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        int top = 0;
        int bottom = matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> ans;
        int size = (bottom+1)*(right+1);
        while(ans.size() < size)
        {
            for(int i = left; i <= right; i++)
            {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        while(ans.size() > size)
        {
            ans.pop_back();
        }
        return ans;
    }
};