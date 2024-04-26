//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        // Code here
        vector<int> result;
        int dir = 0;    // 0->east , 1->south , 2->west , 3->north
        int i = 0 , j = 0;
        
        while(true) {
            if(matrix[i][j] == 0) {
                if(dir == 0) j++;  // Move right
                else if(dir == 1) i++;  // Move down
                else if(dir == 2) j--;  // Move left
                else if(dir == 3) i--;  // Move up
            } else {
                // Change direction and mark the current cell as visited (change 1 to 0)
                matrix[i][j] = 0;
                dir = (dir + 1) % 4;
                if(dir == 0) j++;  // Move right
                else if(dir == 1) i++;  // Move down
                else if(dir == 2) j--;  // Move left
                else if(dir == 3) i--;  // Move up
            }
            
            if(i < 0){
                i++;
                break;
            } else if(j < 0){
                j++;
                break;
            } else if(i == n){
                i--;
                break;
            } else if(j == m){
                j--;
                break;
            }
        }
        result.push_back(i);
        result.push_back(j);
            
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends