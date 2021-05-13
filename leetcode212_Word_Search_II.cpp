class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        const int ROW = board.size(), COL = board[0].size();
        vector<string> res;
        vector<bool> visited(ROW * COL,false);
        vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        
        root = new TrieNode();
        
        for(string word : words)
            insert(word);
        
        function<void(int,int,TrieNode*)> dfs = [&](int r,int c,TrieNode* cur) {
            if(cur->word != ""){
                res.push_back(cur->word);
                eraseWord(cur->word,0,root);
                cur->word = "";
            }
            visited[r * COL + c] = true;
            for(vector<int>& d : dir){
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr == ROW || nc == COL || visited[nr * COL + nc])
                    continue;
                if(cur->children[board[nr][nc] - 'a'] == nullptr)
                    continue;
                dfs(nr,nc,cur->children[board[nr][nc] - 'a']);
            }
            visited[r * COL + c] = false;
        };
        
        for(int r = 0;r < ROW;r++)
            for(int c = 0; c < COL;c++)
                if(root->children[board[r][c] - 'a'] != nullptr)
                    dfs(r,c,root->children[board[r][c] - 'a']);
        
        return res;
    }
private:
    struct TrieNode{
        string word;
        int count;
        vector<TrieNode*> children;
        TrieNode() : count(0), word(""), children(vector<TrieNode*>(26,nullptr)) {}
    };
    TrieNode *root;
    void insert(string& word){
        TrieNode *cur = root;
        for(char c : word){
            if(cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new TrieNode();
            cur->count++;
            cur = cur->children[c - 'a'];
        }
        cur->word = word;
        cur->count++;
    }
    void eraseWord(string& word,int idx,TrieNode* cur){
        if(idx == word.length()){
            cur->count--;
            return;
        }
        eraseWord(word,idx + 1,cur->children[word[idx] - 'a']);
        if(cur->children[word[idx] - 'a']->count == 0)
            cur->children[word[idx] - 'a'] = nullptr;
    }
};
// https://tinyurl.com/ytnxmsym