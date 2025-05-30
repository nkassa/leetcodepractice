class Solution {
public:
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    int maxFreqSum(string s) 
    {
        priority_queue<int> heap;
        priority_queue<int> heap_two;
        unordered_map<char,int> count;
        for(char c: s)
        {
            count[c]++;
        }
        for(auto [key, val]: count)
        {
            if(vowel.find(key) != vowel.end())
            {
                heap.push(val);
            }
            else
            {
                heap_two.push(val);
            }
        }
        if(!heap.empty() && !heap_two.empty())
        {
            return heap.top() + heap_two.top();
        }
        if(!heap.empty())
        {
            return heap.top();
        }
        return heap_two.top();
    }
};