class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        n = 10**18
        res = ""
        for s in strs:
            n = min(n, len(s))

        for i in range(n):
            temp = strs[0][i]
            for s in strs:
                if s[i] != temp:
                    return res
            res = res + temp
            
        return res
