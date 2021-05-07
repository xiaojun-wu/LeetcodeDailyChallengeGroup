class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto cur = root;
        for(char c : word){
            if(cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto cur = root;
        for(char c : word){
            if(cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto cur = root;
        for(char c : prefix){
            if(cur->children[c - 'a'] == nullptr)
                return false;
            cur = cur->children[c - 'a'];
        }
        return true;
    }
private:
    struct TrieNode{
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(vector<TrieNode*>(26,nullptr)) {}
    };
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

 // https://tinyurl.com/jx92fb