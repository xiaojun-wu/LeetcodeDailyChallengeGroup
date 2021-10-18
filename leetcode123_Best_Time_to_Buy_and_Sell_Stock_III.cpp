class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int SIZE = prices.size(), MAXPROFIT = 1e6;
        int firstBuy = INT_MIN, firstSell = 0;
        int secondBuy = INT_MIN, secondSell = 0;
        
        for(int price : prices){
            // update second sell
            secondSell = max(secondSell,secondBuy + price);
            // update second buy
            secondBuy = max(secondBuy,firstSell - price);
            
            // update first sell
            firstSell = max(firstSell,firstBuy + price);
            // update first buy
            firstBuy = max(firstBuy, -price);
        }
        
        return max(secondSell,firstSell);
    }
};

// https://tinyurl.com/48w5tze9