class Solution {
public:

    vector<int> options = {1, 2};

    int climbStairs(int n) 
    {
        string curr = "";
        unordered_set<string> seen;
        backtrack(curr, seen, n, 0);
        return seen.size();
    }
    void backtrack(string& curr, unordered_set<string>& seen, int& n, int total)
    {
        if(total == n)
        {
            seen.insert(curr);
            return;
        }
        else if(total > n)
        {
            return;
        }
        for(int option: options)
        {
            curr += option;
            total += option;
            backtrack(curr, seen, n , total);
            curr.pop_back();
            total -= option;
        }
    }
};