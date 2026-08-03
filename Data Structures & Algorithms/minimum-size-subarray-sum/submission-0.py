class Solution:
    def minSubArrayLen(self, target: int, nums: List[int]) -> int:
        res = 10**18
        l = 0
        sums = 0

        for r in range(len(nums)):
            sums += nums[r]
            print(sums)
            while sums >= target:
                res = min(res, r - l + 1)
                sums -= nums[l]
                l += 1
        return 0 if res == 10**18 else res