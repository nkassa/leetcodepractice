class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int carry = 0;
        string ans = "";
        int size1 = num1.size()-1;
        int size2 = num2.size()-1;
        while(size1 >= 0 && size2 >= 0)
        {
            int digit = (num1[size1]-  '0') + (num2[size2] - '0') + carry;
            if(digit > 9)
            {
                ans += to_string(digit % 10);
                carry = digit/10;
            }
            else
            {
                ans += to_string(digit);
                carry = 0;
            }
            size1--;
            size2--;
        }
        while(size1 >= 0)
        {
            int digit = (num1[size1]-  '0')  + carry;
            if(digit > 9)
            {
                ans += to_string(digit % 10);
                carry = digit/10;
            }
            else
            {
                ans += to_string(digit);
                carry = 0;
            }
            size1--;
        }
        while(size2 >= 0)
        {
            int digit = (num2[size2]-  '0')  + carry;
            if(digit > 9)
            {
                ans += to_string(digit % 10);
                carry = digit/10;
            }
            else
            {
                ans += to_string(digit);
                carry = 0;
            }
            size2--;
        }
        if(carry > 0)
        {
            ans += to_string(carry);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};