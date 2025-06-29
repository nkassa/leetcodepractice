class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) 
    {
        priority_queue<pair<string,string>, vector<pair<string,string>>, greater<pair<string,string>>> heapLetter;
        vector<string> digits;
        for(string str: logs)
        {
            int i = 0;
            string s = "";
            while(str[i] != ' ')
            {
                s += str[i];
                i++;
            }
            int n = str.size()-1;
            if(str[n] - '0' < 10)
            {
                
                digits.push_back(str);
            }
            else
            {
                int size = n-i;
                heapLetter.push({str.substr(i+1, size), s});
            }
        }
        vector<string> ans;
        while(!heapLetter.empty())
        {
            string s = heapLetter.top().second + ' ' + heapLetter.top().first;
            heapLetter.pop();
            ans.push_back(s);
        }
        for(string s: digits)
        {
            ans.push_back(s);
        }
        return ans;
    }
};