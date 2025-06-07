class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        int cnt = num1.size()-1;
        int cnt_two = num2.size()-1;
        int rem = 0;
        long int sum = 0;
        int digit = 1;
        while(cnt >= 0 && cnt_two >= 0)
        {
            sum += ((num2[cnt_two]- '0' + num1[cnt] - '0' + rem) % 10) * digit;
            rem = ((num2[cnt_two]-'0' + num1[cnt] - '0' + rem) / 10);
            digit *= 10;
            cnt--;
            cnt_two--;
        }
        while(cnt >= 0 || rem > 0)
        {
            sum += ((num1[cnt] - '0' + rem) % 10)*digit;
            rem = ((num1[cnt] - '0' + rem) / 10);
            digit *= 10;
            cnt--;
        }
        while(cnt_two >= 0 || rem > 0)
        {
            sum += ((num2[cnt_two] - '0' + rem) % 10)*digit;
            rem = ((num2[cnt_two] - '0' + rem) / 10);
            digit *= 10;
            cnt_two--;
        }
        return to_string(sum);
    }
};