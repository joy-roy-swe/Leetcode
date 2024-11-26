class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        # Array to track the in-degree of each team
        in_degree = [0] * n

        # Update in-degree for each losing team
        for winner, loser in edges:
            in_degree[loser] += 1

        answer = -1
        count = 0

        # Find the team with in-degree 0
        for i in range(n):
            if in_degree[i] == 0:
                count += 1
                answer = i

        # If there's exactly one team with in-degree 0, return it
        if count == 1:
            return answer

        return -1