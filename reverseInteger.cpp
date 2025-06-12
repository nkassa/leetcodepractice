class Solution {
public:
    int reverse(int x) 
    {
        string s = to_string(x);
        int left = 0;
        int right = s.size()-1;
        while(left < right)
        {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            right--;
            left++;
        }
        if(stol(s) > pow(2,31))
        {
            return 0;
        }
        if(x < 0)
        {
            return 0 - stoi(s);
        }
        return stoi(s);
    }
};//
