class WordFilter {
public:
    WordFilter(vector<string>& words) {
        trie = new Trie(words);
    }
    
    int f(string prefix, string suffix) {
        return trie->search(prefix,suffix);
    }
private:
    struct TrieNode{
        vector<TrieNode*> children;
        set<int,greater<int>> indice;
        TrieNode(){
            children = vector<TrieNode*>(26,nullptr);
        }
    };
    class Trie{
        public:
        Trie(vector<string>& words){
            prefixRoot = new TrieNode();
            suffixRoot = new TrieNode();
            for(int i = 0;i < words.size();i++){
                insertPrefix(words[i],i);
                insertSuffix(words[i],i);
            }
        }
        void insertPrefix(string word,int idx){
            TrieNode *cur = prefixRoot;
            for(char c : word){
                if(cur->children[c - 'a'] == nullptr)
                    cur->children[c - 'a'] = new TrieNode();
                cur = cur->children[c - 'a'];
                cur->indice.insert(idx);
            }
        }
        void insertSuffix(string word,int idx){
            TrieNode *cur = suffixRoot;
            for(int i = word.length() - 1;i >= 0;i--){
                if(cur->children[word[i] - 'a'] == nullptr)
                    cur->children[word[i] - 'a'] = new TrieNode();
                cur = cur->children[word[i] - 'a'];
                cur->indice.insert(idx);
            }
        }
        int search(string prefix,string suffix){
            TrieNode *prefixCur = prefixRoot, *suffixCur = suffixRoot;
            for(int i = 0;i < prefix.length() && prefixCur;i++)
                prefixCur = prefixCur->children[prefix[i] - 'a'];
            for(int i = suffix.length() - 1;i >= 0;i--)
                suffixCur = suffixCur->children[suffix[i] - 'a'];
            if(prefixCur == nullptr || suffixCur == nullptr){
                // cout<<"empty"<<endl;
                return -1;
            }
            auto it1 = prefixCur->indice.begin(), it2 = suffixCur->indice.begin();
            while(it1 != prefixCur->indice.end() && it2 != suffixCur->indice.end()){
                if(*it1 == *it2)
                    return *it1;
                else if(*it1 > *it2)
                    it1++;
                else
                    it2++;
            }
            return -1;
        }
        private:
        TrieNode *prefixRoot, *suffixRoot;
    };
    Trie *trie;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */

// https://tinyurl.com/445shatj