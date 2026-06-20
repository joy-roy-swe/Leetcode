class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        frequency = Counter(text)
        instances = float('inf')

        for ch in "balon":
            if frequency[ch] == 0:
                return 0

            count = frequency[ch]
            if ch in ('l', 'o'):
                count //= 2

            instances = min(instances, count)

        return instances
