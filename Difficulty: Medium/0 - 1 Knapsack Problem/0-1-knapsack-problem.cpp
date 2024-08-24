//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int dp[1002][1002];

 int solve(int W,vector<int>&wt,vector<int>&val,int n){
        // base case 
        if(n==0 || W==0) return 0;
        if(dp[n][W] != -1) return dp[n][W];
        if(wt[n-1]<=W){
            return dp[n][W]=max((val[n-1]+solve(W-wt[n-1],wt,val,n-1)),solve(W,wt,val,n-1));
        }else{
            return solve(W,wt,val,n-1);
        }
    }

int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=val.size();
        memset(dp,-1,sizeof(dp));
        return solve(W,wt,val,n);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends