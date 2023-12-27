int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) {
        return 0;
    }
    
    vector<int> buy(n, 0);
    vector<int> sell(n, 0);
    
    buy[0] = prices[0];
    
    for (int i = 1; i < n; i++) {
        buy[i] = min(buy[i-1], prices[i]);
        sell[i] = max(sell[i-1], prices[i] - buy[i-1]);
    }
    
    int maxProfit = sell[n-1];
    int maxSell = prices[n-1];
    
    for (int i = n-2; i >= 0; i--) {
        maxSell = max(maxSell, prices[i]);
        maxProfit = max(maxProfit, maxSell - prices[i] + sell[i]);
    }
    
    return maxProfit;
}
