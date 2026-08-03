class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool end = false;
};

class WordDictionary {
private:
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char c : word) {
            int index = c - 'a';
            if (cur->children[index] == nullptr)
                cur->children[index] = new TrieNode();
            cur = cur->children[index]; // ✅ advance
        }
        cur->end = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }

private:
    bool dfs(TrieNode* node, const string& word, int i) {
        if (!node) return false;

        if (i == word.size())
            return node->end;

        char c = word[i];
        if (c == '.') {
            // Try all possible children
            for (int j = 0; j < 26; j++) {
                if (node->children[j] && dfs(node->children[j], word, i + 1))
                    return true;
            }
            return false;
        } else {
            int index = c - 'a';
            return dfs(node->children[index], word, i + 1);
        }
    }
};
