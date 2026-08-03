class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) 
    {
        int temp = 0;
        unordered_map<char, int> sequence;
        for(const char& ch : order)
            sequence[ch] = temp++;

        for(int i=0; i< words.size()-1; i++)
        {
            int size = min(words[i].size(), words[i+1].size());
            int j = 0;
            while(j < size)
            {
                if(words[i][j] != words[i+1][j])
                {
                    if(sequence[words[i][j]] > sequence[words[i+1][j]])
                        return false;
                    break;
                }
                j++;
            }
            if(j == size)
            {
                if(words[i].size() > words[i+1].size())
                    return false;
            }
        }
        return true;
    }
};