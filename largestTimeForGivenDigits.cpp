class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) 
    {
        int maxMin = -1;
        sort(arr.begin(), arr.end());
        do 
        {
            int hour = arr[0] * 10 + arr[1];
            int minute = arr[2] * 10 + arr[3];
            if(hour < 24 && minute < 60)
            {
                int currMin = (hour * 60) + minute;
                maxMin = max(maxMin, currMin);
            }
        }
        while(next_permutation(arr.begin(), arr.end()));
        if(maxMin == -1)
        {
            return "";
        }
        string ans = "";
        int hour = maxMin / 60;
        int minute = maxMin % 60;
        return format("{:02}:{:02}", hour, minute); 
    }
};