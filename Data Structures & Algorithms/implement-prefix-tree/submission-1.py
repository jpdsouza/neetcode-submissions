class TrieNode:
    def __init__(self):
        self.node = [None] * 26   # 26 lowercase letters
        self.end = False


class PrefixTree:

    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for ch in word:
            index = ord(ch) - ord('a')
            if cur.node[index] is None:
                cur.node[index] = TrieNode()
            cur = cur.node[index]
        cur.end = True

    def search(self, word: str) -> bool:
        cur = self.root
        for ch in word:
            index = ord(ch) - ord('a')
            if cur.node[index] is None:
                return False
            cur = cur.node[index]
        return cur.end

    def startsWith(self, prefix: str) -> bool:
        cur = self.root
        for ch in prefix:
            index = ord(ch) - ord('a')
            if cur.node[index] is None:
                return False
            cur = cur.node[index]
        return True