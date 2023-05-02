int maxProfit(vector<int>& arr) {
    int n = arr.size();

    int minPrice = INT_MAX;
    int maxEarning = INT_MIN;

    for(int i = 0; i < n; i++){
        // har step par update karo most minimum price of stock
        minPrice = min(minPrice, arr[i]);
        
        // har step par update karo max profit earned, current price par sell karo aur most minimum par buy ie: (arr[i]-minPrice)
        maxEarning = max(maxEarning, arr[i]-minPrice);
    }

    return maxEarning;
}