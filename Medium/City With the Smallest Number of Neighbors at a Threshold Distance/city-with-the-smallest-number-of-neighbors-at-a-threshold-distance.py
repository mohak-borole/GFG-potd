#User function Template for python3

from typing import List
import heapq

class Solution:
    def findCity(self, n : int, m : int, edges : List[List[int]], distanceThreshold : int) -> int:
        # Create graph
        graph = [[] for _ in range(n)]
        for edge in edges:
            from_city, to_city, weight = edge
            graph[from_city].append((to_city, weight))
            graph[to_city].append((from_city, weight))  # Adding bidirectional edge
        
        min_reachable_cities = float('inf')
        optimal_city = -1

        # Iterate through each city
        for i in range(n):
            distances = [float('inf')] * n
            pq = [(0, i)]
            distances[i] = 0

            # Dijkstra's Algorithm
            while pq:
                curr_distance, curr_city = heapq.heappop(pq)

                for neighbor, neighbor_distance in graph[curr_city]:
                    new_distance = curr_distance + neighbor_distance
                    if new_distance <= distanceThreshold and new_distance < distances[neighbor]:
                        distances[neighbor] = new_distance
                        heapq.heappush(pq, (new_distance, neighbor))

            # Count reachable cities
            reachable_cities = sum(1 for d in distances if d <= distanceThreshold)

            # Update optimal city
            if reachable_cities < min_reachable_cities or (reachable_cities == min_reachable_cities and i > optimal_city):
                min_reachable_cities = reachable_cities
                optimal_city = i

        return optimal_city

#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == '__main__':
    T = int(input())
    for t in range(T):
        
        n, m = map(int, input().strip().split())
        edges = []
        for i in range(m):
            u, v, wt = map(int, input().strip().split())
            edges.append([u, v, wt])
        distanceThreshold = int(input())
        obj = Solution()
        ans = obj.findCity(n, m, edges, distanceThreshold)
        print(ans)
            

# } Driver Code Ends