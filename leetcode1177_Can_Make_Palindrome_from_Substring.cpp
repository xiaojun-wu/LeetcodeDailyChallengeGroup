class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        /*
        prefix sum
        TC: O(LEN + SIZE), SC: O(LEN * 26)
        */
        const int LEN = s.length(), SIZE = queries.size();
        vector<vector<int>> presum(1,vector<int>(26,0));
        vector<bool> res;
        
        for(int i = 0;i < LEN;i++){
            presum.push_back(presum.back());
            presum.back()[s[i] - 'a']++;
        }
        
        for(int i = 0;i < SIZE;i++){
            int l = queries[i][0], r = queries[i][1], k = queries[i][2];
            int odds = 0;
            for(int j = 0;j < 26;j++)
                odds+= (presum[r + 1][j] - presum[l][j]) % 2;
            res.push_back(k >= ceil((odds - 1) / 2.0));
        }
        
        return res;
    }
};