class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INFINITY;
        int max_profit = 0;
        int profit = 0;
        for(int i : prices) {
            if (i < min_price) {
                min_price = i;
            }
            profit = i - min_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        return max_profit;
    }
};
