from typing import List
class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        n = len(code)
        output = []
        if(k == 0):
            output = [0]*n
            return output
        elif(k > 0):
            for idx in range(n):
                sum = 0
                for ik in range(1, k+1):
                    sum += code[(idx+ik)%n]
                output.append(sum)
        else:
            for idx in range(n):
                sum = 0
                for ik in range(k, 0):
                    sum += code[(idx+ik)%n]
                output.append(sum)
        return output