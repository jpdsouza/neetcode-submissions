class Solution:
  def rob(self, nums: List[int]) -> int:

    if len(nums) == 1:
      return nums[0]
    if len(nums) == 2:
      return max(nums[0], nums[1])

    def robber(houses):
      dp = [houses[0], max(houses[0], houses[1])]
      for house in houses[2:]:
        val = max(dp[-2] + house, dp[-1])
        dp.append(val)
      return dp[-1]
    
    return max(robber(nums[1:]), robber(nums[:-1]))
        