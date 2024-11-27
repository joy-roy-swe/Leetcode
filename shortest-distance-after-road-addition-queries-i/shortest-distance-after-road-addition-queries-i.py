from collections import deque, defaultdict

class Solution:
    def shortestDistanceAfterQueries(self, n, queries):
        # Initialize the graph with default roads
        graph = defaultdict(list)
        for i in range(n - 1):
            graph[i].append(i + 1)

        def bfs_shortest_path():
            """Perform BFS to calculate shortest path from 0 to n-1."""
            visited = [False] * n
            queue = deque([(0, 0)])  # (current_city, distance)
            visited[0] = True
            
            while queue:
                city, distance = queue.popleft()
                if city == n - 1:  # Reached city n-1
                    return distance
                for neighbor in graph[city]:
                    if not visited[neighbor]:
                        visited[neighbor] = True
                        queue.append((neighbor, distance + 1))
            
            return float('inf')  # No path to n-1 (shouldn't happen per constraints)

        # Process each query and compute the shortest path
        result = []
        for u, v in queries:
            graph[u].append(v)  # Add the new road
            shortest_path = bfs_shortest_path()
            result.append(shortest_path)
        
        return result
