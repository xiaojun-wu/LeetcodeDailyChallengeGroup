class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        const int SIZE = requests.size(), TOTAL = 1 << SIZE;
        int res = 0;
        int count[20] = {0};
        
        for(int i = 1;i < TOTAL;i++){
            for(int j = 0;i >> j > 0;j++)
                if(i >> j & 1){
                    count[requests[j][0]]--;
                    count[requests[j][1]]++;
                }
            bool isValid = true;
            for(int j = 0;j < 20;j++){
                if(count[j] != 0)
                    isValid = false;
                count[j] = 0;
            }
            if(isValid)
                res = max(res,(int)bitset<16>(i).count());
        }
        
        return res;
    }
};