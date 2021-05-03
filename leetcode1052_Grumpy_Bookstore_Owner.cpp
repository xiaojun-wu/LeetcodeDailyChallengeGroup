class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        const int SIZE = customers.size();
        int res = 0;
        for(int i = 0;i < SIZE;i++)
            res+= customers[i] * !grumpy[i];
        int right = 0, sum = 0, curSum = 0;
        for(;right < X - 1;right++)
            curSum+= customers[right] * grumpy[right];
        for(;right < SIZE;right++){
            curSum+= customers[right] * grumpy[right];
            sum = max(sum,curSum);
            curSum-= customers[right - X + 1] * grumpy[right - X + 1];
        }
        
        return res + sum;
    }
};