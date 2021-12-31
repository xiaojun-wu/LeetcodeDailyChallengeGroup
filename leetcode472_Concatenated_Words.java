class Solution {
    public List<String> findAllConcatenatedWordsInADict(String[] words) {
        Trie trie = new Trie(words);
        Arrays.sort(words,(a,b) -> a.length() - b.length());
        List<String> res = new ArrayList<>();
        for(int i = 0;i < words.length;i++){
            Boolean dp[] = new Boolean[words[i].length()];
            // System.out.println("size : " + dp.length);
            if(trie.search(words[i],0,0,dp)){
                res.add(words[i]);
            }
        }

        return res;
    }
}
class TrieNode{
    public TrieNode[] children;
    public boolean isWord;

    public TrieNode(){
        children = new TrieNode[26];
        isWord = false;
    }
}
class Trie{
    private TrieNode root;

    public Trie(String[] words){
        this.root = new TrieNode();
        for(int i = 0;i < words.length;i++){
            String word = words[i];
            TrieNode cur = root;
            for(int j = 0;j < word.length();j++){
                if(cur.children[word.charAt(j) - 'a'] == null){
                    cur.children[word.charAt(j) - 'a'] = new TrieNode();
                }
                cur = cur.children[word.charAt(j) - 'a'];
            }
            cur.isWord = true;
        }
    }
    public void insert(String word){
        TrieNode cur = root;
        for(int j = 0;j < word.length();j++){
            if(cur.children[word.charAt(j) - 'a'] == null){
                cur.children[word.charAt(j) - 'a'] = new TrieNode();
            }
            cur = cur.children[word.charAt(j) - 'a'];
        }
        cur.isWord = true;
    }
    public boolean search(String word,int idx,int count,Boolean[] dp){
        if(idx < word.length() && dp[idx] != null){
            return false;
        }
        if(idx == word.length()){
            return count > 1;
        }
        TrieNode cur = root;
        for(int i = idx;i < word.length();i++){
            if(cur.children[word.charAt(i) - 'a'] == null){
                dp[idx] = false;
                return false;
            }
            cur = cur.children[word.charAt(i) - 'a'];
            if(cur.isWord && search(word,i + 1,count + 1,dp)){
                return true;
            }
        }
        dp[idx] = false;
        return false;
    }
}

// https://tinyurl.com/3m6akzpu