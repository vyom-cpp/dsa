#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        minPrice = min(minPrice, prices[i]);
        maxProfit = max(maxProfit, prices[i] - minPrice);
    }

    return maxProfit;
}

int main()
{
    vector<int> prices = {7, 5, 3};
    cout << maxProfit(prices) << endl;
    return 0;
}