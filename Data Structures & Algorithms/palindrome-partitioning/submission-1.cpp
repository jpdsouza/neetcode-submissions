class Solution {
public:
    vector<vector<string>> result;
    int n;

    bool isPalindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtracking(const string& s, vector<string>& perm, int start) {
        if (start == n) {
            result.push_back(perm);
            return;
        }

        for (int end = start; end < n; end++) {
            if (isPalindrome(s, start, end)) {
                perm.push_back(s.substr(start, end - start + 1));
                backtracking(s, perm, end + 1);
                perm.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        n = s.length();
        vector<string> perm;
        backtracking(s, perm, 0);
        return result;
    }
};
