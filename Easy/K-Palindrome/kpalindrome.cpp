//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(string &str,int i,int j){
       if(i>=j) return 0;
       int &ans= dp[i][j];
       if(ans!=-1) return ans;
       
       if(str[i]== str[j]){
           return solve(str,i+1,j-1); //no deletion needed
       }
        return  (ans=  1+  min(solve(str,i+1,j) , solve(str,i,j-1)) );
    }
    int kPalindrome(string str, int n, int k)
    {
        // code here
      memset(dp,-1,sizeof(dp));
      int op=  solve(str,0,n-1);
      if(op<=k) return true;
      return false;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends