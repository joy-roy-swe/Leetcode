class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        total_profit = 0
        buy_price = prices[0]

        for current_price in prices[1:]:
            if current_price > buy_price:
                profit = current_price - buy_price
                total_profit += profit
                
            buy_price = current_price
            
        return total_profit