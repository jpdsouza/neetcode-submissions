class Solution {
public:
    bool isPalindrome(string s) {
        for (int i = 0; i < s.length(); i++)
            s[i] = tolower(s[i]);

        int start = 0, end = s.length() - 1;

        while (start < end) {
            if (!isalnum(s[start])) {
                start++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }

        return true;
    }
};
