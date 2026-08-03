class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        dp = set()
        dp.add(0)
        target = total // 2
        for num in nums:
            for val in dp.copy():
                dp.add(val + num)
                if target in dp:
                    return True
        return False