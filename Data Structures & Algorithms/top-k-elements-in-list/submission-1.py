class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        freq = Counter(nums)
        h = []
        res = []

        for key, value in freq.items():
            heapq.heappush(h, [value, key])
            if len(h) > k:
                heapq.heappop(h)

        for l in h:
            res.append(l[1])

        return res