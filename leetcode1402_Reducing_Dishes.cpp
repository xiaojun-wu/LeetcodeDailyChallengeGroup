class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        const int SIZE = satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int res = INT_MIN;
        for(int i = 0;i < SIZE;i++){
            int sum = 0;
            for(int j = i,k = 1;j < SIZE;j++,k++)
                sum+= satisfaction[j] * k;
            if(sum < res) break;
            res = max(res,sum);
        }
        
        return res < 0?0:res;
    }
};