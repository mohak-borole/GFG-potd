//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> ans; 
    void func(int x , int y ,vector<vector<int>> &mat , string curr) {
        if(x<0 || y<0 || x >= mat.size() || y >= mat.size() || mat[x][y] == 0) return;
        
        if(x == mat.size()-1 && y == mat.size()-1){
            ans.push_back(curr);
            return;
        }
        
        mat[x][y] = 0;
        func(x , y+1 , mat , curr+"R");
        func(x+1 , y , mat , curr+"D");
        func(x-1 , y , mat , curr+"U");
        func(x , y-1 , mat , curr+"L");
        
        mat[x][y] = 1;
    }
  
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int n = mat.size();
        if(mat[0][0] == 0 || mat[n-1][n-1] == 0) return {"-1"};
        ans = {};
        func(0 , 0 , mat , "");
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends