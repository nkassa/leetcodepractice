class Solution {
public:
    int distributeCandies(vector<int>& candyType) 
    {
        unordered_set<int> seen(candyType.begin(), candyType.end());
        return min(seen.size(), candyType.size()/2);
    }
};