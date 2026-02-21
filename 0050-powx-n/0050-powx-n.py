class Solution:
    def myPow(self, x: float, n: int) -> float:

        def cal_power(x, n):
            if x == 0:
                return 0
            if n == 0:
                return 1
            
            res = cal_power(x, n // 2)
            res = res * res

            if n % 2 == 1:
                return res * x
            
            return res

        ans = cal_power(x, abs(n))

        if n >= 0:
            return ans
        
        return 1 / ans 