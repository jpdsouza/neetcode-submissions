from collections import defaultdict

class Solution:
  def accountsMerge(self, accounts: List[List[str]]) -> List[List[str]]:
    n = len(accounts)
    emailToAcc = {}
    par = [i for i in range(n)]
    rank = [1] * n

    def find(i):
      if par[i] != i:
        par[i] = find(par[i])
      return par[i]

    def union(p1, p2):
      p1 = find(p1)
      p2 = find(p2)

      if p1 == p2:
        return

      if rank[p1] > rank[p2]:
        rank[p1] += rank[p2]
        par[p2] = p1
      else:
        rank[p2] += rank[p1]
        par[p1] = p2

    for i, acc in enumerate(accounts):
      for email in acc[1:]:
        if email not in emailToAcc:
          emailToAcc[email] = i
        else:
          union(emailToAcc[email], i)

    group = defaultdict(list)

    for email, parent in emailToAcc.items():
      leader = find(parent)
      group[leader].append(email)

    res = []

    for leader, emails in group.items():
      res.append([accounts[leader][0]] + sorted(emails))

    return res