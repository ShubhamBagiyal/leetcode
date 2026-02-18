// LeetCode 121. Best Time to Buy and Sell Stock
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int maxprofit = 0;
    int minPrice = prices[0];

    for(int i = 1; i < prices.size(); i++) {
        int currprofit = prices[i] - minPrice;
        if(currprofit > maxprofit)
            maxprofit = currprofit;

        if(prices[i] < minPrice)
            minPrice = prices[i];
    }

    return maxprofit;
}

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    vector<int> prices(n);
    cout << "Enter prices: ";
    for(int i = 0; i < n; i++)
        cin >> prices[i];

    int result = maxProfit(prices);

    cout << "Maximum Profit: " << result << endl;

    return 0;
}
