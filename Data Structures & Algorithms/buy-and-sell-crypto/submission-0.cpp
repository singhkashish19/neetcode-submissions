class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprft = 0;
        int bestbuy = prices[0];
        int n = prices.size();
        for(int i = 1; i<n; i++){
            if(prices[i]> bestbuy){
                maxprft = max(maxprft, prices[i] - bestbuy);
            }
            bestbuy = min(bestbuy, prices[i]);
        }
        return maxprft;
    }
};
