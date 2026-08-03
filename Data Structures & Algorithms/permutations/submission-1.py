class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        res = []
        subset = []
        visited = [False] * n

        def dfs():
            if len(subset) == n:
                res.append(subset.copy())
                return

            for j in range(n):
                if visited[j]:
                    continue

                visited[j] = True
                subset.append(nums[j])

                dfs()

                subset.pop()
                visited[j] = False

        dfs()
        return res
