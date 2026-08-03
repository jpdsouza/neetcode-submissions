class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs.sort()
        group = dict()
        res = []

        for s in strs:
            key = ''.join(sorted(s))
            if key not in group:
                group[key] = []
            group[key].append(s)

        for val in group.values():
            res.append(val)
        return res
        