class Solution:
    def colorTheArray(self, n: int, queries: List[List[int]]) -> List[int]:
        result = []
        colors = [0] * n
        counter = 0

        def pair_score(i, j):
            """1 if this pair contributes to counter, else 0"""
            return 1 if colors[i] != 0 and colors[i] == colors[j] else 0

        for idx, color in queries:
            # Step 1: Remove old contributions of pairs touching idx
            if idx > 0:
                counter -= pair_score(idx - 1, idx)
            if idx < n - 1:
                counter -= pair_score(idx, idx + 1)

            # Step 2: Apply the update
            colors[idx] = color

            # Step 3: Add new contributions of pairs touching idx
            if idx > 0:
                counter += pair_score(idx - 1, idx)
            if idx < n - 1:
                counter += pair_score(idx, idx + 1)

            result.append(counter)

        return result