class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
        n1 = len(word1)
        n2 = len(word2)
        res = ""
        i = j = 0

        while i < n1 and j < n2:
            res += word1[i]
            res += word2[j]
            i += 1
            j += 1

        if i != (n1 - 1):
            res += word2[j:n2]
        if j != (n2 - 1):
            res += word1[i:n1]

        return res
        