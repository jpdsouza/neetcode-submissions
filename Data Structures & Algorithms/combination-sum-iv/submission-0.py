class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        dp = defaultdict(int)
        dp[0] = 1

        for total in range(1, target + 1):
            for n in nums:
                dp[total] += dp[total - n]
        return dp[target]