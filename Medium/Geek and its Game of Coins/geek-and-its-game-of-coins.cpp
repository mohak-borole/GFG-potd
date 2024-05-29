//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findWinner(int n, int x, int y) {
        // code here
         vector<vector<int>>dp(n+1 , vector<int>(2 , 0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        dp[1][0] = 1;
        dp[1][1] = 1;
        
        for(int i=2;i<=n;i++)
        {
            bool ans1 = false;
            bool ans2 = false;
            if(i >= x)
            {
                ans1|= !dp[i-x][1];
                ans2|= !dp[i-x][0];
            }
        
            if(i >= y)
            {
                 ans1|=!dp[i-y][1];
                 ans2|=!dp[i-y][0];
                
            }
            
            if(ans1 == false)
            {
                ans1|= !dp[i-1][1];
                ans2|= !dp[i-1][0];
            }
            
            dp[i][0] = ans1;
            dp[i][1] = ans2;
        }
        
        return dp[n][0];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        int res = obj.findWinner(n, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends