class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        s = set()
        l = 0
        n = len(nums)
        for r in range(n):
            if (r - l) > k:
                s.remove(nums[l])
                l += 1
            if nums[r] in s:
                return True
            s.add(nums[r])
        return False