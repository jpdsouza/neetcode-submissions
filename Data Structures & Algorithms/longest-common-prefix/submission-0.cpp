class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string res = "";
        for(int i=0; i< strs[0].length(); i++)
        {
            char ch = strs[0][i];
            for(string s : strs)
            {
                if(s[i] != ch)
                    return res;
            }
            res.push_back(ch);
        }
        return res;
    }
};