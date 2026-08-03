import heapq
from typing import List, Dict

class Solution:
    def shortestPath(self, n: int, edges: List[List[int]], src: int) -> Dict[int, int]:
        graph = [[] for _ in range(n)]
        for u, v, w in edges:
            graph[u].append((v, w))

        distance = [float('inf')] * n
        distance[src] = 0

        h = [(0, src)]

        while h:
            dist, node = heapq.heappop(h)

            if dist > distance[node]:
                continue

            for neigh, wt in graph[node]:
                if distance[neigh] > dist + wt:
                    distance[neigh] = dist + wt
                    heapq.heappush(h, (distance[neigh], neigh))

        res = {}
        for i, d in enumerate(distance):
            res[i] = d if d != float('inf') else -1

        return res
