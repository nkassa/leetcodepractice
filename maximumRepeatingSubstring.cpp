class Solution {
public:
    string sequence;
    string word;
    vector<int> memo;
    int maxRepeating(string sequence, string word) 
    {
        this->sequence = sequence;
        this->word = word;
        memo = vector(sequence.size(), 0);
        return dp(0, 0);
    }
    int dp(int seqIdx, int wordIdx)
    {
        if(seqIdx == sequence.size())
        {
            return 0;
        }
        if(wordIdx == word.size())
        {
            return 1;
        }
        int ans = 0;
        if(sequence[seqIdx] == word[wordIdx])
        {
            ans += dp(seqIdx + 1, wordIdx + 1);
        }
        else
        {
            ans +=  dp(seqIdx + 1, 0);
        }
        memo[seqIdx] = ans;
        return memo[seqIdx];
    }
};