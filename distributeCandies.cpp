class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        int n = candyType.size()/2;
        unordered_set<int> seen;
        for(int num: candyType)
        {
            seen.insert(num);
        }
        int size = seen.size();
        return min(size, n);
    }
};