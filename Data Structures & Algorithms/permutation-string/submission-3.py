from collections import Counter, defaultdict

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        freq1 = Counter(s1)
        freq2 = defaultdict(int)

        k = len(s1)
        l = 0

        for r in range(len(s2)):
            freq2[s2[r]] += 1

            if r - l + 1 > k:
                freq2[s2[l]] -= 1
                if freq2[s2[l]] == 0:
                    del freq2[s2[l]]
                l += 1

            if r - l + 1 == k:
                if freq1 == freq2:
                    return True

        return False
