class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet;
        int length = 0;
        int left = 0;
        int right = 0;
        while(right < s.length())
        {
            if(!charSet.count(s[right]))
            {
                length = max(length, right - left + 1);
                charSet.insert(s[right++]);
            }
            if(charSet.count(s[right]))
            {
                charSet.erase(s[left++]);
            }
        }
        return length;
    }
};
