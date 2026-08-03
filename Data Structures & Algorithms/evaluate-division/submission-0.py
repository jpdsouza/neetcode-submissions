class Solution:
  def calcEquation(self, equations: List[List[str]], values: List[float], queries: List[List[str]]) -> List[float]:
    graph = defaultdict(list)
    nodes = set()

    for i, (u, v) in enumerate(equations):
      graph[u].append([v, values[i]])
      graph[v].append([u, 1 / values[i]])
      nodes.add(u)
      nodes.add(v)
    
    def bfs(node, target):
      if node not in nodes or target not in nodes:
        return -1

      q = deque()
      q.append([node, 1]) 
      s = set()
      s.add(node)

      while q:
        u, w = q.popleft()
        if u == target:
          return w
        for v, weight in graph[u]:
          if v not in s:
            s.add(v)
            q.append([v, w * weight])

      return float(-1)
    
    res = [0] * len(queries)
    for i, (u, v) in enumerate(queries):
      res[i] = bfs(u, v)
    
    return res
          

