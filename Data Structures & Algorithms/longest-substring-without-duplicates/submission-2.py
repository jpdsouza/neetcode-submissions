class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen = set()
        l = 0
        n = len(s)
        length = 0
        for r in range(n):
            while s[r] in seen:
                seen.remove(s[l])
                l += 1

            seen.add(s[r])
            length = max(length, len(seen))

        return length
        