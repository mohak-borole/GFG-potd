//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  #define ll long long
  public:
    
     vector<vector<vector<ll>>> dp = vector<vector<vector<ll>>>(26, vector<vector<ll>>(4, vector<ll>(3, -1)));
    
    ll diffSeq(int n, int i, int j)
    {
        if(i<0 || i>3 || j<0 || j>=3 || n<=0 || (i==3 && j!=1)) return 0;
        if(n == 1) return 1;
        if(dp[n][i][j] != -1) return dp[n][i][j];
        int dir[5] = {0, 1, 0, -1, 0};
        ll ans = 0;
        for(int k = 0; k<4; ++k)
        {
            ans += diffSeq(n-1, i+dir[k], j + dir[k+1]);
        }
        ans += diffSeq(n-1, i, j);
        return dp[n][i][j] = ans;
    }
    long long getCount(int n) {
        ll ans = 0;
        for(int i = 0; i<3; ++i)
        {
            for(int j = 0; j<3; ++j)
            ans += diffSeq(n, i, j);
        }
        ans += diffSeq(n, 3, 1);
        
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

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends