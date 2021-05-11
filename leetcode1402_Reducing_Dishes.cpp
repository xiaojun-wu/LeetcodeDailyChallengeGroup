class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int SIZE = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int res = 0, presum = 0;
        for(int i = SIZE - 1;i >= 0 && satisfaction[i] + presum > 0;i--){
            presum+= satisfaction[i];
            res+= presum;
        }
        
        return res;
    }
};
// https://tinyurl.com/ut9963tc