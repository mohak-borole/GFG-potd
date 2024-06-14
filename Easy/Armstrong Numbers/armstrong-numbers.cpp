//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    #define ll long long int
    string armstrongNumber(int n) {
        // code here
        ll f=(n/100)%10, m=(n/10)%10, l=n%10;
        ll sum = (f*f*f)+(m*m*m)+(l*l*l);

        if(sum==n) return "true";
        else return "false";
        
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends