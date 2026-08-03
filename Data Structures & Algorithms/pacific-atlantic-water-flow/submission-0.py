class Solution:
  def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
    row = len(heights)
    col = len(heights[0])
    pacific = [[False] * col for _ in range(row)]    
    atlantic = [[False] * col for _ in range(row)]
    directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
    pq = deque()    
    aq = deque()    
    res = []

    for i in range(row):
      pacific[i][0] = True
      pq.append([i, 0])
    for j in range(col):
      pacific[0][j] = True
      pq.append([0, j])

    for i in range(row):
      atlantic[i][col-1] = True
      aq.append([i, col-1])
    for j in range(col):
      atlantic[row-1][j] = True
      aq.append([row-1, j])

    while pq:
      r, c = pq.popleft()
      for dr, dc in directions:
        nr, nc = r + dr, c + dc
        if 0 <= nr < row and 0 <= nc < col and heights[r][c] <= heights[nr][nc] and not pacific[nr][nc]:
          pq.append([nr, nc])
          pacific[nr][nc] = True

    while aq:
      r, c = aq.popleft()
      for dr, dc in directions:
        nr, nc = r + dr, c + dc
        if 0 <= nr < row and 0 <= nc < col and heights[r][c] <= heights[nr][nc] and not atlantic[nr][nc]:
          aq.append([nr, nc])
          atlantic[nr][nc] = True
          
    for i in range(row):
      for j in range(col):
        if pacific[i][j] and atlantic[i][j]:
          res.append([i, j])

    return res
