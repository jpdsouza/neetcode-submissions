class Solution:
  def getConcatenation(self, nums: List[int]) -> List[int]:
    size = len(nums) * 2
    res = [-1] * size
    for i in range(len(nums)):
      res[i] = nums[i]
      res[len(nums) + i] = nums[i]
    return res