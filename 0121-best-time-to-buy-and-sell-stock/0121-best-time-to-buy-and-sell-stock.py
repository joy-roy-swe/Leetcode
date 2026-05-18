class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        buy = prices[0]
        for price in prices[1:]:
            if buy > price:
                buy = price
                continue
            max_profit = max(max_profit, (price-buy))
        return max_profit