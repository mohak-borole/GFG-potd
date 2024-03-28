//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for (const auto& edge : edges) {
            int from = edge[0];
            int to = edge[1];
            int weight = edge[2];
            graph[from].push_back({to, weight});
            graph[to].push_back({from, weight}); // Adding bidirectional edge
        }

        int minReachableCities = INT_MAX;
        int optimalCity = -1;

        // Iterate through each city
        for (int i = 0; i < n; ++i) {
            vector<int> distances(n, INT_MAX);
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
            pq.push({0, i});
            distances[i] = 0;

            // Dijkstra's Algorithm
            while (!pq.empty()) {
                int currDistance = pq.top().first;
                int currCity = pq.top().second;
                pq.pop();

                for (const auto& neighbor : graph[currCity]) {
                    int neighborCity = neighbor.first;
                    int neighborDistance = neighbor.second;
                    int newDistance = currDistance + neighborDistance;
                    if (newDistance <= distanceThreshold && newDistance < distances[neighborCity]) {
                        distances[neighborCity] = newDistance;
                        pq.push({newDistance, neighborCity});
                    }
                }
            }

            // Count reachable cities
            int reachableCities = 0;
            for (int j = 0; j < n; ++j) {
                if (distances[j] <= distanceThreshold) {
                    ++reachableCities;
                }
            }

            // Update optimal city
            if (reachableCities < minReachableCities || (reachableCities == minReachableCities && i > optimalCity)) {
                minReachableCities = reachableCities;
                optimalCity = i;
            }
        }

        return optimalCity;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends