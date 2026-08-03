class Solution:
    def integerBreak(self, n: int) -> int:
        dp = {}

        def dfs(x):
            if x == 1:
                return 1
            
            if x in dp:
                return dp[x]
            
            res = 0
            
            for i in range(1, x):
                j = x - i
                res = max(
                    res,
                    i * j,       
                    i * dfs(j)    
                )
            
            dp[x] = res
            return res
        
        return dfs(n)