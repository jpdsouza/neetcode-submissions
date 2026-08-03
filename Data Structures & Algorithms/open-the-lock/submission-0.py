class Solution:
  def openLock(self, deadends: List[str], target: str) -> int:

    def children(lock):
      res = []
      for i in range(4):
        digit = str((int(lock[i]) + 1) % 10)
        res.append(lock[:i] + digit + lock[i+1:])

        digit = str((int(lock[i]) - 1 + 10) % 10)
        res.append(lock[:i] + digit + lock[i+1:])
      return res

    if '0000' in deadends:
      return -1
    if '0000' == target:
      return 0
    visited = set(deadends)
    q = deque()
    q.append(['0000', 0]) #lock, turns

    while q:
      lock, turns = q.popleft()
      if lock == target:
        return turns
      for child in children(lock):
        if child not in visited:
          visited.add(child)
          q.append([child, turns + 1])
    return -1
        



