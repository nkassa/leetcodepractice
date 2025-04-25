class Solution {
public:
    string sequence;
    string word;
    int ans = 0;
    int maxRepeating(string sequence, string word) 
    {
        this->sequence = sequence;
        this->word = word;
        return dp(0, 0);
    }
    int dp(int seqIdx, int wordIdx)
    {
        if(seqIdx == sequence.size())
        {
            return ans;
        }
        if(wordIdx == word.size())
        {
            return 1;
        }
        if(sequence[seqIdx] == word[wordIdx])
        {
            ans += dp(seqIdx + 1, wordIdx + 1);
        }
        else
        {
            ans +=  dp(seqIdx + 1, 0);
        }
        return ans;
    }
};