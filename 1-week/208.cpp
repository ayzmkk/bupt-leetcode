struct TrieNode {
    bool isKey;
    TrieNode* children[26];
    TrieNode(): isKey(false) {
        memset(children, NULL, sizeof(children));
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* ans = root;
        for (auto i : word) {
            if (!ans->children[i - 'a']) ans->children[i - 'a'] = new TrieNode();
            ans = ans->children[i - 'a'];
        }
        ans->isKey = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* ans = root;
        for (auto i : word) {
            if (!ans->children[i - 'a']) return false;
            ans = ans->children[i - 'a'];
        }
        return ans->isKey;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* ans = root;
        for (auto i : prefix) {
            if (!ans->children[i - 'a']) return false;
            ans = ans->children[i - 'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
