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
                ans.push_back(matrix[i][top]);
            }
            top++;
            for(int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[right][i]);
            }
            right--;
            for(int i = right; i >= left; i--)
            {
                ans.push_back(matrix[i][bottom]);
            }
            bottom--;
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[left][i]);
            }
        }
        return ans;
    }
};