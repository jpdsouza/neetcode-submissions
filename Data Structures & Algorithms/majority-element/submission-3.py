class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        ele = nums[0]
        count = 0
        for n in nums:
            if n == ele:
                count = count + 1
            else:
                count -= 1
                if count < 0:
                    ele = n
                    count = 0
        return ele
        