class Solution:
    def wordBreak(self, s: str, wordDict):
        n = len(s)

        maxLen = max(len(word) for word in wordDict)
        hashSet = set(wordDict)

        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(1, n + 1):
            for j in range(i - 1, -1, -1):
                if i - j > maxLen:
                    break

                if s[j:i] in hashSet and dp[j]:
                    dp[i] = True
                    break

        return dp[n]