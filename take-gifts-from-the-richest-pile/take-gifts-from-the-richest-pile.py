from typing import List
from math import sqrt

class Solution:
    def pickGifts(self, gifts: List[int], k: int) -> int:
        while k:
            gifts.sort(reverse=True)
            pile = gifts[0]
            gifts.pop(0)
            gifts.append(int(sqrt(pile)))
            k -= 1
        return sum(gifts)