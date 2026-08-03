class TrieNode
{
    public:
        TrieNode* children[26];
        bool end;
        
        TrieNode()
        {
            for(int i=0; i<26; i++)
                children[i] = nullptr;
            end = false;
        }
};

class PrefixTree 
{
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        for(char c : word)
        {
            int index = c - 'a';
            if(cur->children[index] == nullptr)
                cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->end = true;
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for(char c : word)
        {
            int index = c - 'a';
            if(cur->children[index] == nullptr)
                return false;
            cur = cur->children[index];
        }
        return cur->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(char c : prefix)
        {
            int index = c - 'a';
            if(cur->children[index] == nullptr)
                return false;
            cur = cur->children[index];
        }
        return true;
    }
};
