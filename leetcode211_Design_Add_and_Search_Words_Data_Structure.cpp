class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* cur = root;
        for(char c : word){
            if(cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }
    
    bool search(string word) {
        return search(word,root,0);
    }
private:
    struct TrieNode{
        bool isWord;
        vector<TrieNode*> children;
        TrieNode() : isWord(false), children(vector<TrieNode*>(26,nullptr)){}
    };
    TrieNode* root;
    bool search(string& word,TrieNode* cur,int idx){
        if(idx == word.length())
            return cur->isWord;
        for(int i = idx;i < word.length();i++){
            if(word[i] == '.'){
                for(auto child : cur->children)
                    if(child && search(word,child,i + 1))
                        return true;
                return false;
            }
            if(cur->children[word[i] - 'a'] == nullptr)
                return false;
            cur = cur->children[word[i] - 'a'];
        }
        return cur->isWord;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

 // https://tinyurl.com/2jbjjutv