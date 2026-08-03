class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        s = set(nums)
        res = 0

        for num in nums:
            if (num - 1) not in s:
                l = 1
                while ( num + l) in s:
                    l += 1
                res = max(l, res)
        return res