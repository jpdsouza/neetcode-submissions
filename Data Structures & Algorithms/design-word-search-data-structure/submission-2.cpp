class TrieNode {
public:
    TrieNode* children[26];
    bool end;

    TrieNode() {
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
        end = false;
    }
};

class WordDictionary {
private:
    TrieNode* root;

    bool backtracking(TrieNode* node, string& word, int index)
    {
        if (index == word.length())
            return node->end;

        char ch = word[index];
        if (ch == '.') {
            for (int i = 0; i < 26; i++) {
                if (node->children[i] && backtracking(node->children[i], word, index + 1))
                    return true;
            }
            return false;
        } else {
            int ascii = ch - 'a';
            if (!node->children[ascii])
                return false;
            return backtracking(node->children[ascii], word, index + 1);
        }
    }

public:
    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            int ascii = ch - 'a';
            if (cur->children[ascii] == nullptr)
                cur->children[ascii] = new TrieNode();
            cur = cur->children[ascii];
        }
        cur->end = true;
    }

    bool search(string word) {
        return backtracking(root, word, 0);
    }
};
