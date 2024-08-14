//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        int n = str1.size();
        int m = str2.size();
        
        int maxi = 0;  // Initialize maxi to 0 instead of INT_MIN
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    maxi = max(maxi, dp[i][j]);
                }
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends