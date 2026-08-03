class Solution {
public:
    unordered_map<char, string> keypad;
    vector<string> result;
    int n;
    Solution()
    {
        keypad[2] = "abc";
        keypad[3] = "def";
        keypad[4] = "ghi";
        keypad[5] = "jkl";
        keypad[6] = "mno";
        keypad[7] = "pqrs";
        keypad[8] = "tuv";
        keypad[9] = "wxyz";
    }
    void backtracking(const string& digits, string str, int start)
    {
        if(start == n)
        {
            result.push_back(str);
            return;
        }
        // string s = keypad[digits[start] - '0'];
        for(char ch : keypad[digits[start] - '0'])
        {
            str.push_back(ch);
            backtracking(digits, str, start+1);
            str.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) 
    {
        n = digits.length();
        if(n == 0)
            return {};
        backtracking(digits, "", 0);
        return result;
    }
};
