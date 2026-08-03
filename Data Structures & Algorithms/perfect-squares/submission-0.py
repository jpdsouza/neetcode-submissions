class Solution:
    def numSquares(self, n: int) -> int:
        nums = [i*i for i in range(1, int(math.sqrt(n)) + 1)]
        
        dp = [float('inf')] * (n + 1)
        dp[0] = 0
        
        for target in range(1, n + 1):
            for square in nums:
                if target - square < 0:
                    break
                dp[target] = min(dp[target], 1 + dp[target - square])
        
        return dp[n]