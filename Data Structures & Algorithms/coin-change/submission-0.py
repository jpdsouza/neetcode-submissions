class Solution:
  def coinChange(self, coins: List[int], amount: int) -> int:
    if amount == 0:
      return 0

    q = deque()
    q.append([0, 0])#amt, coins
    s = set()

    while q:
      amt, count = q.popleft()

      for coin in coins:
        total = amt + coin
        if total == amount:
          return count + 1

        if total < amount and total not in s:
          q.append([total, count + 1])
          s.add(total)
    
    return -1