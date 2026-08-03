class Solution:
    def maxArea(self, heights: List[int]) -> int:
        l, r = 0, len(heights)-1
        area = 0
        while l <= r:
            a = heights[l]
            b = heights[r]

            area = max(area, (r-l) * min(a, b))
            if min(a, b) == a:
                l += 1
            else:
                r -= 1
        return area