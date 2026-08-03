class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        h = []
        res = []

        for x, y in points:
            d = (x**2 + y**2) **0.5
            heapq.heappush(h, [-d, x, y])
            if len(h) > k:
                heapq.heappop(h)
        for d, x, y in h:
            res.append([x, y])
        return res
