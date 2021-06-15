class Solution {
public:
    int longestWPI(vector<int>& hours) {
        /*
        prefix sum
        TC:O(N), SC:O(10002)
        */
        const int SIZE = hours.size();
        vector<int> mp(10002,-1);
        int sum = 0, res = 0;
        
        for(int i = 0;i < SIZE;i++){
            sum+= hours[i] > 8?1:-1;
            if(sum > 0)
                res = i + 1;
            else{
                if(mp[-sum + 1] != -1)
                    res = max(res,i - mp[-sum + 1]);
                if(mp[-sum] == -1)
                    mp[-sum] = i;
            }
        }
        
        return res;
    }
};
// https://tinyurl.com/y9955sdy