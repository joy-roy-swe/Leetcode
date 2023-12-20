class Solution {
public:
    int buyChoco(std::vector<int>& prices, int money) {
        // Sort the vector in ascending order to get the lowest prices first
        sort(prices.begin(), prices.end());

        // Calculate the sum of the two lowest prices of chocolate
        int two_chocolate_price = prices[0] + prices[1];

        // Check if the given amount is sufficient to buy two chocolates
        if (money >= two_chocolate_price) {
            // Return the remaining money after buying two chocolates
            return money - two_chocolate_price;
        }

        // Return the original amount if it is not sufficient to buy two chocolates
        return money;
    }
};