class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();

        string result = "";
        int temp1 = 0;
        int temp2 = 0;

        while(temp1 < l1 && temp2 < l2)
        {
            result.push_back(word1[temp1++]);
            result.push_back(word2[temp2++]);
        }
        while(temp1 < l1)
            result.push_back(word1[temp1++]);
        while(temp2 < l2)
            result.push_back(word2[temp2++]);
        return result;
    }
};