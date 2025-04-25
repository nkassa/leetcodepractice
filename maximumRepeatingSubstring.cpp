class Solution {
public:
    int maxRepeating(string sequence, string word) 
    {
        int ans = 0;
        int seqIdx = 0;
        int wordIdx = 0;
        while(seqIdx != sequence.size())
        {
            cout << ans << " " << seqIdx << " " << wordIdx << endl;
            if(sequence[seqIdx] == word[wordIdx])
            {
                wordIdx++;
            }
            else
            {
                wordIdx = 0;
            }
            if(wordIdx == word.size())
            {
                ans++;
                wordIdx = 0;
            }
            seqIdx++;
        }
        return ans;
    }
};